#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define WIDTH 900
#define HEIGHT 600


void draw_at_grid_coordinate(SDL_Surface *psurface, SDL_Rect *prect, Uint32 color)
{
    int x_grid = WIDTH/2 + prect->x;
    int y_grid = HEIGHT/2 - prect->y;
    SDL_Rect shifted_rect = (SDL_Rect) {x_grid, y_grid, prect->w, prect->h};
    SDL_FillRect(psurface, &shifted_rect, color);

}

void draw_grid(SDL_Surface *psurface) 
{
    SDL_Rect x_axis;
    x_axis.x = -WIDTH / 2;
    x_axis.y = 0;
    x_axis.w = WIDTH;
    x_axis.h = 2;

    SDL_Rect y_axis;
    y_axis.x = 0;
    y_axis.y = HEIGHT / 2;
    y_axis.w = 2;
    y_axis.h = HEIGHT;
    draw_at_grid_coordinate(psurface, &x_axis, 0xFFFFFF);
    draw_at_grid_coordinate(psurface, &y_axis, 0xFFFFFF);
    
}


int main()
{
    printf("Hello World!\n");
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return 1;
}
    
    SDL_Window *pwindow = SDL_CreateWindow("Plotter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    

    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
    SDL_Rect rect = (SDL_Rect) {50,50, 50, 50};
    Uint32 color = 0xFF0000FF;
 
    
    draw_grid(psurface);
    draw_at_grid_coordinate(psurface, &rect, color);
    
    SDL_UpdateWindowSurface(pwindow);

    SDL_Event event;
    bool app_running = true;
    while(app_running){
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            app_running = 0;
        }

    }
}

SDL_Quit();
return 0;


}