#include <iostream>
#include <cstdlib>




int print_board(char map[][100], int x, int y) {

    for (int i = y-1; i >= 0; i--) {
        for (int j = 0; j < x; j++) {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
    for (int j = 0; j < x; j++) {
        std::cout << "-";
    }
    std::cout << std::endl;
    
    
    return 0;
}


int main(void) {

    srand (time(NULL));
    int sizex = 100;
    int sizey = 30;

    double dt = 0.1;
    double g = -9.81;

    double x, y, vx, vy;
    char map[30][100];
    bool hit = 0;
    for (int i = 0; i < sizey; i++) {
        for (int j = 0; j < sizex; j++) {
            map[i][j] = ' ';
        }
    }

    int stand = rand() % sizey;
    int goal_x = rand() % 20 + 80;
    int goal_y = rand() % 30;
    char temp;
    stand = 0;
    map[0][stand] = '@';
    map[goal_y][goal_x] = 'O';
    
    while (!hit) {
        x = 0;
        y = 0;

        print_board(map, sizex, sizey);

        for (int i = 0; i < sizey; i++) {
            for (int j = 0; j < sizex; j++) {
                map[i][j] = ' ';
            }
        }

        std::cout << "vx: "; 
        std::cin >> vx;
        std::cout << "vy: ";
        std::cin >> vy;
        std::cout << "Fire, when ready..." << std::endl;
        std::cin.get(temp);

        int pos_x, pos_y;
        while (y >= 0 || vy >= 0) {

            x = x + vx * dt;
            y = y + vy * dt;
            vy = vy + g * dt;
            //std::cout << x << " " << y << " " << vx << " "<< vy << std::endl;

            pos_x = (int) x / 100;
            pos_y = (int) y / 100;
            if (pos_x >= sizex || pos_y >= sizey) {
                continue;
            }
            map[pos_y][pos_x] = 'x';
            if (pos_y == goal_y && pos_x == goal_x) {
                hit = 1;
                break;
            }
        }

        map[0][stand] = '@';
        map[goal_y][goal_x] = 'O';
    }

    print_board(map, sizex, sizey);
    std::cout << "Aye! We hit the target Sir!" << std::endl;

    return 0;
}




