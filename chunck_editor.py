import pygame
import pickle
from os import path


pygame.init()

def create_level(whatchunck):

    # VARIABLES CHANGEANTES -----------------------------------------------------------------------------------------------------


    nb_sprites = 3
    chunck = whatchunck


    # ----------------------------------------------------------------------------------------------------------------------------

    #autres variables
    whattodraw = 2
    whattodraw2 = 1

    clock = pygame.time.Clock()
    fps = 60
    tile_size = 50
    marge = 90
    clr_black = (0,0,0)
    font_bauhaus_40 = pygame.font.SysFont("Bauhaus 93", 40)
    screen_width, screen_height = pygame.display.Info().current_w, pygame.display.Info().current_h
    screen= pygame.display.set_mode((0,0),pygame.FULLSCREEN)

    #les images
    bg_img = pygame.image.load('assets/chunck_editor/img_background1.webp')
    img_objects = pygame.image.load("assets/chunck_editor/img_background_objects.webp")
    img_objects_2 = pygame.image.load("assets/chunck_editor/img_background_objects_2.webp")
    img_objects = pygame.transform.scale(img_objects, (screen_width, 100))
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

    SPRITES = [
        None,
        wall_img,
        loot_img,
        enemy_img
    ]

    #les couleurs
    white = (255, 255, 255)
    green = (144, 201, 120)
    black = (0,0,0)

    level_x = -4
    level_y = 4

    #création d'une liste vide -----------------------------------------------------------------------------------------------------------------------
    world_data = []
    for _ in range(22):
        r = [0] * 100
        world_data.append(r)

    #remplissage par défaut
    for tile in range(0, 22):
        world_data[tile][0] = 1
        world_data[tile][99] = 1
    for tile in range(0, 50):
        world_data[19][tile] = 2
        world_data[20][tile] = 1
        world_data[21][tile] = 1

    def draw_grid():
        for i in range(screen_width // tile_size):
            pygame.draw.line(screen, black, (i * tile_size, 0), (i * tile_size, screen_height - marge))
        for i in range(screen_height // tile_size):
            pygame.draw.line(screen, black, (0, i * tile_size), (screen_width, i * tile_size))

    def draw_text(texte, font, couleur, x, y):
        img = font.render(texte, True, couleur)
        screen.blit(img, (x, y))

    objets = [  wall_img, 
                loot_img,
                enemy_img]

    numero = [1,2,3]

    for i in range(len(objets)):
        objets[i] = pygame.transform.scale(objets[i],(screen_width // (nb_sprites + 2) - 5 ,screen_width // (nb_sprites + 2) - 5))

    def draw_world():
        if len(world_data) == 20:
            for row in range(2):
                r = [0] * 100
                world_data.append(r)
        for row in range(level_y, 22):
            for col in range(level_x, 100):
                if world_data[row][col] > 0:
                    img = pygame.transform.scale(SPRITES[world_data[row][col]], (tile_size, tile_size))
                    screen.blit(img, ((col-level_x) * tile_size, (row-level_y) * tile_size))


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

    #main loop ------------------------------------------------------------------------------------------------------------



    run = True
    while run:
        key = pygame.key.get_pressed()

        clock.tick(fps)

        screen.blit(bg_img, (0, 0))

        draw_world()
        draw_grid()

        img_objects = pygame.transform.scale(img_objects, (screen_width, 100))
        screen.blit(img_objects, (0, screen_height - 90))
        screen.blit(img_objects, (0,-40))
        img_objects = pygame.transform.scale(img_objects, (50, screen_height))
        screen.blit(img_objects, (0,0))
        screen.blit(img_objects, (screen_width - 50, 0))	
        img_objects_2 = pygame.transform.scale(img_objects_2, ((screen_width // (nb_sprites + 2) - 5) * (nb_sprites + 5) , screen_width // (nb_sprites) + 20))
        screen.blit(img_objects_2, (screen_width // 2 - (screen_width // (nb_sprites + 2) * (nb_sprites // 2 + 1)) - 27, screen_height - 85))

        draw_text(f"Chunck {whatchunck % 100}", font_bauhaus_40, clr_black, 20, 10)

        if save_button.draw():
            world_data[18][98] = 1378
            for tile in range(0, 100):
                if not world_data[20][tile] == 0:
                    world_data[20][tile] = 1
                    world_data[21][tile] = 1
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


        for i in range(len(objets)):
            bouton_objets = Bouton(screen_width // 2 + (screen_width // (nb_sprites + 2)) * (i - nb_sprites // 2 - 1), screen_height - 70, objets[i])
            if bouton_objets.draw():
                whattodraw = numero[i]
                whattodraw2 = i
            img_whattodraw = pygame.transform.scale(objets[whattodraw2], (screen_width // 25, screen_width // 25))
            screen.blit(img_whattodraw, (screen_width - (screen_width // 25 + 70), 75))

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
                    world_data[y][x] = 0

            if key[pygame.K_RIGHT]:
                level_x += 2
                draw_world()
            if key[pygame.K_LEFT]:
                level_x -= 2
                draw_world()
            if key[pygame.K_DOWN]:
                level_y += 2
                draw_world()
            if key[pygame.K_UP]:
                level_y -= 2
                draw_world()

        #update la fenetre
        pygame.display.update()


if __name__ == "__main__":
    create_level(1)