#ifndef _MUSIC_H
#define _MUSIC_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>

// Initializes the music system. This function should be called before any other music functions.
Mix_Music* init_music(char* music_path);
// This function starts playing the music that has been loaded.
void play_music(Mix_Music* musique);
// Stops the currently playing music.
void stop_music(Mix_Music* musique);

#endif