import pygame
import pickle
from os import path
from enum import Enum


pygame.init()

def create_level(whatchunck):

    # VARIABLES -----------------------------------------------------------------------------------------------------

    nb_sprites = 3
    ROW, COL = 40, 80
    chunck = whatchunck
    whattodraw = 0
    clock = pygame.time.Clock()
    fps = 60
    tile_size = 20
    marge = 90
    clr_black = (0,0,0)
    level_x = -4
    level_y = 4
    font_bauhaus_40 = pygame.font.SysFont("Bauhaus 93", 40)
    display_info = pygame.display.Info()
    screen_width, screen_height = display_info.current_w, display_info.current_h
    screen_dims = (screen_width, screen_height)
    screen = pygame.display.set_mode((0,0),pygame.FULLSCREEN)

    #les images
    bg_img = pygame.image.load('assets/chunck_editor/img_background1.webp')
    img_objects = pygame.image.load("assets/chunck_editor/img_background_objects.webp")
    img_objects = pygame.transform.scale(img_objects, (screen_width, 100))
    img_objects_2 = pygame.image.load("assets/chunck_editor/img_background_objects_2.webp")
    img_objects_2 = pygame.transform.scale(img_objects_2, (screen_width * 90 // 100, screen_height // tile_size * 4))
    wall_img = pygame.image.load('assets/chunck_editor/wall.webp')
    wall_img = pygame.transform.scale(wall_img, (50,50))
    loot_img = pygame.image.load('assets/chunck_editor/loot.webp')
    loot_img = pygame.transform.scale(loot_img, (50,50))
    enemy_img = pygame.image.load('assets/chunck_editor/enemy.webp')
    enemy_img = pygame.transform.scale(enemy_img, (50,50))
    save_img = pygame.image.load('assets/chunck_editor/img_bouton_save.webp')
    save_img = pygame.transform.scale(save_img, (200,46))
    load_img = pygame.image.load('assets/chunck_editor/img_bouton_load.webp')
    load_img = pygame.transform.scale(load_img, (200,46))
    exit_b_img = pygame.image.load("assets/chunck_editor/img_bouton_exit.webp")
    exit_b_img = pygame.transform.scale(exit_b_img, (90,50))

    BG_IMG = 0
    IMG_OBJECTS = 1
    IMG_OBJECTS_2 = 2
    WALL_IMG = 3
    LOOT_IMG = 4
    ENEMY_IMG = 5
    SAVE_IMG = 6
    LOAD_IMG = 7
    EXIT_B_IMG = 8
        
    images = [
        bg_img,
        img_objects,
        img_objects_2,
        wall_img,
        loot_img,
        enemy_img,
        save_img,
        load_img,
        exit_b_img
    ]

    SPRITES = [
        wall_img,
        loot_img,
        enemy_img
    ]

    objets = [
        wall_img, 
        loot_img,
        enemy_img
    ]

    class Bouton():
        def __init__(self, x, y, image):
            self.image = image
            self.rect = self.image.get_rect()
            self.rect.topleft = (x, y)
            self.clicked = False

        def draw(self):
            action = False
            pos = pygame.mouse.get_pos()
            if self.rect.collidepoint(pos):
                if pygame.mouse.get_pressed()[0] == 1 and self.clicked == False:
                    action = True
                    self.clicked = True
            if pygame.mouse.get_pressed()[0] == 0:
                self.clicked = False
            screen.blit(self.image, (self.rect.x, self.rect.y))
            return action

    save_button = Bouton(screen_width // 2 - 190, 7, save_img)
    load_button = Bouton(screen_width // 2 + 50, 7, load_img)
    exit_button = Bouton(screen_width - 140, 7, exit_b_img)


    #création d'une liste vide -----------------------------------------------------------------------------------------------------------------------
    world_data = []
    for _ in range(ROW):
        r = [-1] * COL
        world_data.append(r)

    #remplissage par défaut
    for tile in range(0, 22):
        world_data[tile][0] = 1
        world_data[tile][COL-1] = 1
    #quadrillage de départ
    def draw_grid(screen_dims):
        for i in range(screen_dims[0] // tile_size):
            pygame.draw.line(screen, clr_black, (i * tile_size, 0), (i * tile_size, screen_dims[1] - marge))
        for i in range(screen_dims[1] // tile_size):
            pygame.draw.line(screen, clr_black, (0, i * tile_size), (screen_dims[0], i * tile_size))

    #fonction pour afficher du texte
    def draw_text(texte, font, couleur, x, y):
        img = font.render(texte, True, couleur)
        screen.blit(img, (x, y))

    #fonction pour afficher le world
    def draw_world():
        for row in range(level_y, ROW):
            for col in range(level_x, COL):
                if not 0 < row < ROW-1 or not 0 < col < COL-1:
                    screen.blit(SPRITES[0], ((col-level_x) * tile_size, (row-level_y) * tile_size))
                if world_data[row][col] >= 0:
                    img = pygame.transform.scale(SPRITES[world_data[row][col]], (tile_size, tile_size))
                    screen.blit(img, ((col-level_x) * tile_size, (row-level_y) * tile_size))

    def draw_overlay(images, screen_dims):
        images[IMG_OBJECTS] = pygame.transform.scale(images[IMG_OBJECTS], (screen_dims[0], 100))
        screen.blit(images[IMG_OBJECTS], (0, screen_dims[1] - 90))
        screen.blit(images[IMG_OBJECTS], (0,-40))
        images[IMG_OBJECTS] = pygame.transform.scale(images[IMG_OBJECTS], (50, screen_dims[1]))
        screen.blit(images[IMG_OBJECTS], (0,0))
        screen.blit(images[IMG_OBJECTS], (screen_dims[0] - 50, 0))
        screen.blit(images[IMG_OBJECTS_2], (screen_dims[0] * 5 // 100, screen_dims[1] - 85))



    #main loop ------------------------------------------------------------------------------------------------------------



    run = True
    while run:
        
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False

            #clics pour changer les tiles
            pos = pygame.mouse.get_pos()
            x = pos[0] // tile_size + level_x
            y = pos[1] // tile_size + level_y
            #check de la pos de la souris
            if x < 100 and y < 22 and 60 < pos[1] < screen_height - 100:
                #update de la tile
                if pygame.mouse.get_pressed()[0] == 1:
                    world_data[y][x] = whattodraw
                elif pygame.mouse.get_pressed()[2] == 1:
                    world_data[y][x] = -1
        
        
        key = pygame.key.get_pressed()
        clock.tick(fps)
        screen.blit(bg_img, (0, 0))
        draw_world()
        draw_grid(screen_dims)
        draw_overlay(images, screen_dims)
        draw_text(f"Chunck {whatchunck % 100}", font_bauhaus_40, clr_black, 20, 10)

        if save_button.draw():
            pickle_out = open(f'levels/level{chunck}_data', 'wb')
            pickle.dump(world_data, pickle_out)
            pickle_out.close()

        if load_button.draw():
            if path.exists(f'levels/level{chunck}_data'):
                pickle_in = open(f'levels/level{chunck}_data', 'rb')
                world_data = pickle.load(pickle_in)

        if exit_button.draw():
            pygame.time.delay(300)
            run=False

        if key[pygame.K_RIGHT]:
            level_x += 2
            draw_world()
            pygame.time.delay(100)
        if key[pygame.K_LEFT]:
            level_x -= 2
            draw_world()
            pygame.time.delay(100)
        if key[pygame.K_DOWN]:
            level_y += 2
            draw_world()
            pygame.time.delay(100)
        if key[pygame.K_UP]:
            level_y -= 2
            draw_world()
            pygame.time.delay(100)

        for i in range(len(objets)):
            bouton_objets = Bouton(screen_width // 2 + (screen_width // (nb_sprites + 2)) * (i - nb_sprites // 2 - 1), screen_height - 70, objets[i])
            if bouton_objets.draw():
                whattodraw = i
            screen.blit(objets[whattodraw], (screen_width - (screen_width // 25 + 70), 75))

        #update la fenetre
        pygame.display.update()




if __name__ == "__main__":
    create_level(1)