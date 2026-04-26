//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <iso646.h>
//
//#define N 10
//#define INF 10000000000000000ll
//typedef long long int ll;
//
//ll field[N][N];     // веса клеток
//ll dist[N][N];      // минимальные расстояния
//int visited[N][N];   // метки посещения
//int prev_x[N][N], prev_y[N][N]; // для восстановления пути
//
//int dx[4] = { 1, -1, 0, 0 };
//int dy[4] = { 0, 0, 1, -1 };
//
//void generate_field() {
//    srand(time(NULL));
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < N; j++) {
//            if (rand() % 100 < 20) field[i][j] = -1; // 20% препятствий
//            else /*if (rand() % 100 < 10) field[i][j] = rand() % 100; else*/ field[i][j] = /*1;*/rand() % 10 + 1;  // вес 1–10
//        }
//}
//
//void print_field() {
//    printf("Matrica vesov:\n");
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            printf("%3lld", field[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//void wave(int sx, int sy, int fx, int fy) {
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < N; j++) {
//            dist[i][j] = INF;
//            visited[i][j] = 0;
//            prev_x[i][j] = prev_y[i][j] = -1;
//        }
//
//    dist[sx][sy] = 0;
//
//    for (;;) {
//        ll min_dist = INF;
//        int x = -1, y = -1;
//
//        // ищем непосещённую клетку с минимальной дистанцией
//        for (int i = 0; i < N; i++)
//            for (int j = 0; j < N; j++)
//                if (!visited[i][j] and dist[i][j] < min_dist) {
//                    min_dist = dist[i][j];
//                    x = i; y = j;
//                }
//
//        if (x == -1) break; // нет достижимых клеток
//        visited[x][y] = 1;
//        if (x == fx and y == fy) break; // дошли до цели
//
//        // обновляем соседей
//        for (int d = 0; d < 4; d++) {
//            int nx = x + dx[d], ny = y + dy[d];
//            if (nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
//            if (field[nx][ny] == -1) continue; // препятствие
//            ll new_dist = dist[x][y] + field[nx][ny];
//            if (new_dist < dist[nx][ny]) {
//                dist[nx][ny] = new_dist;
//                prev_x[nx][ny] = x;
//                prev_y[nx][ny] = y;
//            }
//        }
//    }
//}
//
//void print_dist() {
//    printf("\nMatrica rasstoyaniy:\n");
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            if (dist[i][j] == INF) printf(" -1");
//            else printf("%3lld", dist[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//void print_path(int fx, int fy) {
//    if (dist[fx][fy] == INF) { printf("\nPuti net\n"); return; }
//    int view[N][N];
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < N; j++)
//            view[i][j] = (field[i][j] == -1 ? '0' : '0');
//
//    int x = fx, y = fy;
//    while (x != -1 && y != -1) {
//        view[x][y] = '1';
//        int px = prev_x[x][y];
//        int py = prev_y[x][y];
//        x = px; y = py;
//    }
//
//    printf("\nPath:\n");
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++)
//            printf("  %c", view[i][j]);
//        printf("\n");
//    }
//}
//
//int main() {
//    generate_field();
//    print_field();
//
//    int sx, sy, fx, fy;
//
//    // --- выбираем старт (слева)
//    do {
//        sx = rand() % N;
//        sy = 0;
//    } while (field[sx][sy] == -1);
//
//    // --- выбираем финиш (справа)
//    do {
//        fx = rand() % N;
//        fy = N - 1;
//    } while (field[fx][fy] == -1 and (fx == sx and fy == sy));
//
//    printf("\nStart: (%d, %d)\nFinish: (%d, %d)\n", sx, sy, fx, fy);
//
//    wave(sx, sy, fx, fy);
//    print_dist();
//    print_path(fx, fy);
//}
//
