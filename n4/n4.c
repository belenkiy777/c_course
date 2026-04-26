#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

// блок рандома
typedef long long int ll;
void init_rng(void) {
    time_t curtime;
    time(&curtime);
    srand((unsigned int)curtime);
    rand(); rand(); rand();
}
int gen_rnd_int(void) { // рандом точки старта / финиша
    ll t = ((ll)rand() * 10) / RAND_MAX;
    return (int)t;
}
int gen_rnd_int2(void) { // рандом количества препятствий
    ll t = ((ll)rand() * 25) / RAND_MAX;
    return (int)t;
}

// изначальное поле
void start_map(char map[N][N], int* start_x, int* start_y, int* finish_x, int* finish_y) {
    // инициализация 1го поля
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = '.';
        }
    }
    // стартовые позиции
    int start_point = gen_rnd_int();
    int finish_point = gen_rnd_int();
    map[start_point][0] = 'S';
    map[finish_point][N - 1] = 'F';
    *start_x = start_point;
    *start_y = 0;
    *finish_x = finish_point;
    *finish_y = N - 1;


    // создание препятствий
    int blocks = gen_rnd_int2();
    int placed = 0;
    while (placed < blocks) {
        int x = gen_rnd_int();
        int y = gen_rnd_int();
        // проверка препятствий
        if (map[x][y] == '.') {
            map[x][y] = '#';
            placed++;
        }
    }
    // отрисовка 1го поля
    printf("\n Start map: \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %c", map[i][j]);
        }
        printf("\n");
    }
}

void wave(char map[N][N], int dist[N][N], int start_x, int start_y, int finish_x, int finish_y) {
    printf("\n Wave algorithm: \n");

    // инициализация второго поля
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dist[i][j] = -1;


    dist[start_x][start_y] = 1;

    int dx[] = { -1, 1, 0, 0 };  // направления движения
    int dy[] = { 0, 0, -1, 1 };

    int iter = 1;

    while (dist[finish_x][finish_y] == -1) { // пока мы не поставили что-то на финиш
        int grew = 0;

        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (dist[x][y] == iter) { // обрабатываем только текущие клетки
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx >= 0 && nx < N && ny >= 0 && ny < N) { // проверка границ карты
                            if ((map[nx][ny] == '.' || map[nx][ny] == 'F') && dist[nx][ny] == -1) { // можем ли мы ходить на следующую клетку
                                dist[nx][ny] = iter + 1;
                                grew = 1;//???? флаг успешного распространения волны, 
                                // если она равна 0, если: следующий ход ограничен границами карты, препятствиями, или соседние клетки уже посещены
                                // нужен, чтобы предотвратить бесконечный цикл
                            }
                        }
                    }
                }
            }
        }
        if (!grew) break;
        iter++;
    }
    // выводим второе поле
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == '#')
                printf(" ##");
            else if (dist[i][j] == -1)
                printf("  .");
            else
                printf("%3d", dist[i][j]);
        }
        printf("\n");
    }
}
// восстановление пути
void recover_wave(char map[N][N], int dist[N][N], int start_x, int start_y, int finish_x, int finish_y) {
    if (dist[finish_x][finish_y] == -1) { // если мы не смогли ничего поставить 
        printf("\n Path is not found. \n");
    }
    else {
        int x = finish_x; // ставим положение на финиш
        int y = finish_y;
        int iter = dist[x][y]; // расстояние до финиша
        while (!(x == start_x && y == start_y)) { // ?????? пока не пришли на старт while (x == start_x && y == start_y) == 0
            // сравнение переменных идет через сравнение с нулем (x - start_x == 0)
            int dx[4] = { -1, 1, 0, 0 };
            int dy[4] = { 0, 0, -1, 1 };
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if (dist[nx][ny] == iter - 1) { // ищем соседнюю клетку, которая меньше нашей
                        if (map[nx][ny] != 'S' && map[nx][ny] != 'F') {
                            map[nx][ny] = '*';
                        }
                        x = nx;
                        y = ny;
                        iter = dist[x][y]; // расстояние уменьшается
                        break; // соседняя клетка найдена, можно идти дальше
                    }
                }
            }
        }
        printf("\n Shortest path: \n");
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %c", map[i][j]);
        }
        printf("\n");
    }
}



int main(void) {
    char map[N][N];
    int dist[N][N];
    init_rng();
    int start_x, start_y;
    int finish_x, finish_y;
    start_map(map, &start_x, &start_y, &finish_x, &finish_y);
    wave(map, dist, start_x, start_y, finish_x, finish_y);
    recover_wave(map, dist, start_x, start_y, finish_x, finish_y);
    return 0;
}