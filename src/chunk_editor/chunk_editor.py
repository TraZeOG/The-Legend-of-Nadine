import pygame
import json
from os import path

pygame.init()

BASE_PATH = 'src/assets/chunks/'

def create_level(name="default", row = 40, col = 80):

    # VARIABLES -----------------------------------------------------------------------------------------------------

    global ROW, COL
    ROW, COL = row, col
    whattodraw = 1
    clock = pygame.time.Clock()
    fps = 60
    tile_size = 20
    marge = 90
    clr_black = (0,0,0)
    level_x = -6
    level_y = -6
    font_bauhaus_40 = pygame.font.SysFont("Bauhaus 93", 40)
    display_info = pygame.display.Info()
    screen_width, screen_height = display_info.current_w, display_info.current_h
    screen_dims = (screen_width, screen_height)
    screen = pygame.display.set_mode((0,0),pygame.FULLSCREEN)

    #les images
    bg_img = pygame.image.load('src/chunk_editor/assets/img_background1.webp')
    img_objects = pygame.image.load("src/chunk_editor/assets/img_background_objects.webp")
    img_objects = pygame.transform.scale(img_objects, (screen_width, 100))
    img_objects_2 = pygame.image.load("src/chunk_editor/assets/img_background_objects_2.webp")
    img_objects_2 = pygame.transform.scale(img_objects_2, (screen_width * 90 // 100, screen_height // tile_size * 4))
    save_img = pygame.image.load('src/chunk_editor/assets/img_bouton_save.webp')
    save_img = pygame.transform.scale(save_img, (200,46))
    load_img = pygame.image.load('src/chunk_editor/assets/img_bouton_load.webp')
    load_img = pygame.transform.scale(load_img, (200,46))
    exit_img = pygame.image.load("src/chunk_editor/assets/img_bouton_exit.webp")
    exit_img = pygame.transform.scale(exit_img, (90,50))
    IMG_OBJECTS = 1
    IMG_OBJECTS_2 = 2
        
    images = [
        bg_img,
        img_objects,
        img_objects_2,
        save_img,
        load_img,
        exit_img
    ]

    objects = [
        "wall",
        "loot",
        "enemy",
        "house",
        "gate",
        "npc",
        "tree",
        "chest",
        "ghost",
        "cactus",
        "fire",
        "cat",
        "toilet",
        "flower",
        "rose",
        "bed",
        "palmier",
        "mountain",
        "moai",
        "amphore",
    ]
    SPRITES = []
    for obj in objects:
        SPRITES.append(pygame.image.load(f'src/chunk_editor/assets/{obj}.webp'))
    nb_sprites = len(SPRITES)

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
    exit_button = Bouton(screen_width - 140, 7, exit_img)


    #création d'une liste vide -----------------------------------------------------------------------------------------------------------------------
    world_data = []
    for _ in range(ROW):
        r = [-1] * COL
        world_data.append(r)

    #remplissage par défaut
    for tile in range(0, ROW):
        world_data[tile][0] = 1
        world_data[tile][COL-1] = 1
    world_data[(ROW-1)//2][0] = -1
    world_data[(ROW-1)//2+1][0] = -1
    world_data[(ROW-1)//2][COL-1] = -1
    world_data[(ROW-1)//2+1][COL-1] = -1
    for tile in range(0, COL):
        world_data[0][tile] = 1
        world_data[ROW-1][tile] = 1
    world_data[0][(COL-1)//2] = -1
    world_data[0][(COL-1)//2+1] = -1
    world_data[ROW-1][(COL-1)//2] = -1
    world_data[ROW-1][(COL-1)//2+1] = -1
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
        for row in range(max(0, level_y), ROW):
            for col in range(max(0, level_x), COL):
                if world_data[row][col] > 0:
                    img = pygame.transform.scale(SPRITES[world_data[row][col]-1], (tile_size, tile_size))
                    screen.blit(img, ((col-level_x) * tile_size, (row-level_y) * tile_size))

    def draw_overlay(images, screen_dims):
        images[IMG_OBJECTS] = pygame.transform.scale(images[IMG_OBJECTS], (screen_dims[0], 100))
        screen.blit(images[IMG_OBJECTS], (0, screen_dims[1] - 90))
        screen.blit(images[IMG_OBJECTS], (0,-40))
        img_objects_scaled = pygame.transform.scale(images[IMG_OBJECTS], (50, screen_dims[1]))
        screen.blit(img_objects_scaled, (0,0))
        screen.blit(img_objects_scaled, (screen_dims[0] - 50, 0))
        screen.blit(images[IMG_OBJECTS], (0,0))
        screen.blit(images[IMG_OBJECTS], (screen_dims[0] - 50, 0))
        screen.blit(images[IMG_OBJECTS_2], (screen_dims[0] * 5 // 100, screen_dims[1] - 85))

    def load_world_data():        
        file_path = f'{BASE_PATH}/{name}.eota'
        if path.exists(file_path):
            with open(file_path, 'r') as file:
                for yindex, line in enumerate(file):
                    if yindex == 0:
                        SIZE = line.split(',')
                        ROW, COL = int(SIZE[0]), int(SIZE[1])
                    else:
                        for xindex, tile in enumerate(line.split(',')):
                            if tile.strip():
                                world_data[yindex - 1][xindex] = int(tile.strip()) - 1

    def save_world_data():
        with open(f'{BASE_PATH}/{name}.eota', 'w') as file:
            file.write(f'{str(ROW)},{str(COL)}\n')
            for row in world_data:
                for bloc in row:
                    file.write(str(bloc+1) + ',')
                file.write('\n')

    #main loop ------------------------------------------------------------------------------------------------------------

    load_world_data()

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
            if x < COL and y < ROW and 60 < pos[1] < screen_height - 100:
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
        draw_text(f"Chunk {name}", font_bauhaus_40, clr_black, 20, 10)

        if save_button.draw():
            save_world_data()
        if load_button.draw():
            load_world_data()
        if exit_button.draw():
            save_world_data()
            pygame.time.delay(300)
            run = False
 
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

        for i in range(len(SPRITES)):
            img = pygame.transform.scale(SPRITES[i], (50, 50))
            bouton_objets = Bouton(screen_width // 2 + (screen_width // (nb_sprites + 2)) * (i - nb_sprites // 2), screen_height - 70, img)
            if bouton_objets.draw():
                whattodraw = i + 1
            SPRITES[whattodraw-1] = pygame.transform.scale(SPRITES[whattodraw-1], (50, 50))
            screen.blit(SPRITES[whattodraw-1], (screen_width - (screen_width // 25 + 70), 75))

        #update la fenetre
        pygame.display.update()

if __name__ == "__main__":
    create_level("house/chunk_house5", 20, 40)
