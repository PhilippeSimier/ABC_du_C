#ifndef SENSE_HAT_H
#define SENSE_HAT_H

#define _GNU_SOURCE
#define DEV_FB "/dev"
#define FB_DEV_NAME "fb"
#define DEV_INPUT_EVENT "/dev/input"
#define EVENT_DEV_NAME "event"

#define ROUGE   0xF800
#define BLEU    0x001F
#define VERT    0x07E0
#define BLANC   0xFFFF
#define NOIR    0x0000
#define ORANGE  0xFC00
#define CYAN    0x87FF
#define MAGENTA 0xF81F
#define JAUNE   0xFFE0


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <dirent.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <linux/input.h>



void     Allumer(unsigned int x, unsigned int y, uint16_t couleur);
uint16_t ObtenirPixel(int x, int y);
void     InitialiserLeds();
void     Effacer();
void     AfficherMotif(uint16_t motif[][8]);
void     InitialiserJoystick();
int ScannerJoystick();

#endif
