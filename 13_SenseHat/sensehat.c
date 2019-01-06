/* Librairie SenseHat pour la gestion des Leds et du Joystick
    Auteurs : Philippe CRUCHET 2015
            : Philippe SIMIER  2018
*/

#include "sensehat.h"

typedef enum{
    FALSE,TRUE
}boolean;


/* Fonctions pour la gestion des leds */
struct fb_t {
	uint16_t pixel[8][8];
};

struct fb_t *fb;

static int is_framebuffer_device(const struct dirent *dir)
{
    return strncmp(FB_DEV_NAME, dir->d_name, strlen(FB_DEV_NAME)-1) == 0;
}

static int open_fbdev(const char *dev_name)
{
	struct dirent **namelist;
	int i, ndev;
	int fd = -1;
	struct fb_fix_screeninfo fix_info;

	ndev = scandir(DEV_FB, &namelist, is_framebuffer_device, versionsort);
	if (ndev <= 0)
		return ndev;

	for (i = 0; i < ndev; i++)
	{
		char fname[64];

		snprintf(fname, sizeof(fname),
			 "%s/%s", DEV_FB, namelist[i]->d_name);
		fd = open(fname, O_RDWR);
		if (fd < 0)
			continue;
		ioctl(fd, FBIOGET_FSCREENINFO, &fix_info);
		if (strcmp(dev_name, fix_info.id) == 0)
			break;
		close(fd);
		fd = -1;
	}
	for (i = 0; i < ndev; i++)
		free(namelist[i]);

	return fd;
}

void Allumer(unsigned int x, unsigned  int y, uint16_t couleur)
{
    fb->pixel[x%8][y%8] = couleur;
}


void InitialiserLeds()
{
    int fbfd ;

    fbfd = open_fbdev("RPi-Sense FB");
	if (fbfd > 0)
	{
            fb = mmap(0, 128, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
            if (!fb)
            {
                printf("Failed to mmap.\n");
                exit(EXIT_FAILURE);
            }
	}
	else
	{
            printf("Error: cannot open framebuffer device.\n");
	    close(fbfd);
            exit(EXIT_FAILURE);

	}
	memset(fb, 0, 128);
}


void Effacer()
{
    memset(fb, 0, 128);
}


void AfficherMotif(uint16_t motif[][8])
{
    memcpy(fb,motif,128);
}


uint16_t ObtenirPixel(int x, int y)
{
    return fb->pixel[x%8][y%8] ;
}


/* Pour le joystick */

int joystick;

static int is_event_device(const struct dirent *dir)
{
	return strncmp(EVENT_DEV_NAME, dir->d_name,
		       strlen(EVENT_DEV_NAME)-1) == 0;
}

static int open_evdev(const char *dev_name)
{
	struct dirent **namelist;
	int i, ndev;
	int fd = -1;
	int sortie = FALSE;

	ndev = scandir(DEV_INPUT_EVENT, &namelist, is_event_device, versionsort);
	if (ndev <= 0)
		exit (EXIT_FAILURE);

    i=0;
    do
    {
        char fname[64];
	char name[256];

	snprintf(fname, sizeof(fname), "%s/%s", DEV_INPUT_EVENT, namelist[i++]->d_name);

	fd = open(fname, O_RDONLY );
	if (fd < 0)
		exit (EXIT_FAILURE);

	ioctl(fd, EVIOCGNAME(sizeof(name)), name);

	if (strcmp(dev_name, name) != 0)
            close(fd);
        else sortie = TRUE;
    }
    while( i<ndev && sortie != TRUE);

    for (i = 0; i < ndev; i++)
	free(namelist[i]);
    return fd;
}

uint16_t handle_events(int evfd)
{
	struct input_event ev;
	int rd;
	uint16_t retour = 0 ;
	int flag;

	flag = fcntl(evfd,F_GETFL,0);
	fcntl(evfd,F_SETFL,flag | O_NONBLOCK | O_NOCTTY);

	rd = read(evfd, &ev, sizeof(struct input_event));
	if(rd > 0)
	{
	    if(ev.type == EV_KEY && ev.value == 1)
            retour = ev.code;

	}
	return retour;
}

void InitialiserJoystick()
{

    joystick = open_evdev("Raspberry Pi Sense HAT Joystick");

}

int ScannerJoystick()
{
    return handle_events(joystick);
}
