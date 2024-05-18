#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <stdio.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int SQUARE_SIZE = 100;

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("SDL2 Blue Background with Red Square",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Main loop flag
    int quit = 0;

    // Event handler
    SDL_Event e;

    // Main loop
    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Set render color to blue (background)
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        // Clear the entire screen to the set color
        SDL_RenderClear(renderer);

        // Set render color to red (rectangle)
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        // Create a rectangle at the center of the screen
        SDL_Rect fillRect = { (WINDOW_WIDTH - SQUARE_SIZE) / 2, (WINDOW_HEIGHT - SQUARE_SIZE) / 2, SQUARE_SIZE, SQUARE_SIZE };
        // Render the rectangle
        SDL_RenderFillRect(renderer, &fillRect);

        // Update screen
        SDL_RenderPresent(renderer);
    }

    // Destroy renderer
    SDL_DestroyRenderer(renderer);

    // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}
