#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define WIDTH 900
#define HEIGHT 600

void draw_grid(SDL_Surface *psurface) 
{
    
}

void draw_at_grid_coordinate(SDL_Surface *psurface, SDL_Rect *prect, Uint32 color)
{
    int x_grid = WIDTH/2 + prect->x;
    int y_grid = HEIGHT/2 - prect->y;
    SDL_Rect shifted_rect = (SDL_Rect) {x_grid, y_grid, prect->w, prect->h};
    SDL_FillRect(psurface, &shifted_rect, color);

}


int main()
{
    printf("Hello World!\n");
    SDL_Window *pwindow = SDL_CreateWindow("Plotter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
    SDL_Rect rect = (SDL_Rect) {WIDTH/2, HEIGHT/2, 50, 50};
    Uint32 color = 0xFF00FF00;
    SDL_FillRect(psurface, &rect, color);
    SDL_UpdateWindowSurface(pwindow);

    draw_at_grid_coordinate(psurface, &rect, color);
    draw_grid(psurface);


    SDL_Event event;
    bool app_running = true;
    while(app_running){
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            app_running = 0;
        }

    }
}


}