//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define N 10  // размер поля
//
//typedef long long int ll;
//void init_rng(void) {
//    time_t curtime;
//    time(&curtime);
//    srand((unsigned int)curtime);
//    rand(); rand(); rand();
//}
//int gen_rnd_int(void) {
//    ll t = ((ll)rand() * 10) / RAND_MAX;
//    return (int)t;
//}
//
//// Исходное поле
//void printInitialField(int field[N][N]) {
//    printf("=== INITIAL FIELD ===\n");
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            if (field[i][j] == -1)
//                printf("  #");
//            else
//                printf("%3d", 0);   
//        }
//        printf("\n");
//    }
//    printf("\n");
//}
//
//void printWaveMatrix(int wave[N][N]) {
//    printf("=== WAVE MATRIX ===\n");
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            if (wave[i][j] == -1) {
//                printf("  #");
//            }
//            else if (wave[i][j] == -2) {
//                printf("   ");   // unexplored stays blank
//            }
//            else {
//                printf("%3d", wave[i][j]);
//            }
//        }
//        printf("\n");
//    }
//    printf("\n");
//}
//
//// Форматирование
//void printFinalPath(int field[N][N], int startX, int startY, int finishX, int finishY, int path_marks[N][N]) {
//    printf("=== FINAL PATH ===\n");
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            if (i == startX && j == startY) {
//                printf("  S");
//            }
//            else if (i == finishX && j == finishY) {
//                printf("  F");
//            }
//            else if (field[i][j] == -1) {
//                printf("  #");
//            }
//            else if (path_marks[i][j]) {
//                printf("  .");
//            }
//            else {
//                printf("   ");
//            }
//        }
//        printf("\n");
//    }
//    printf("\n");
//}
//
//void generateField(int field[N][N], int obstacles, int* startX, int* startY, int* finishX, int* finishY) {
//    // initialize zeros
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < N; j++)
//            field[i][j] = 0;
//
//    // place random obstacles (may overlap — that's fine)
//    for (int k = 0; k < obstacles; k++) {
//        int x = gen_rnd_int();
//        int y = gen_rnd_int();
//        field[x][y] = -1;
//    }
//
//    // random start (left column) and finish (right column)
//    *startX = gen_rnd_int(); *startY = 0;
//    *finishX = gen_rnd_int(); *finishY = N - 1;
//
//    // ensure start and finish are free
//    field[*startX][*startY] = 0;
//    field[*finishX][*finishY] = 0;
//}
//
//// Распространение волны
//void wavePropagation(int field[N][N], int wave[N][N], int startX, int startY, int finishX, int finishY) {
//    int dx[4] = { -1, 1, 0, 0 };
//    int dy[4] = { 0, 0, -1, 1 };
//
//    // initialize wave: -1 = obstacle, -2 = unexplored
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < N; j++)
//            wave[i][j] = (field[i][j] == -1) ? -1 : -2;
//
//    wave[startX][startY] = 0;
//
//    int waveNumber = 0;
//    int found = 0;
//
//    while (1) {
//        int expanded = 0;
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++) {
//                if (wave[i][j] == waveNumber) {
//                    for (int k = 0; k < 4; k++) {
//                        int nx = i + dx[k];
//                        int ny = j + dy[k];
//                        if (nx >= 0 && nx < N && ny >= 0 && ny < N && wave[nx][ny] == -2) {
//                            wave[nx][ny] = waveNumber + 1;
//                            expanded = 1;
//                            if (nx == finishX && ny == finishY) found = 1;
//                        }
//                    }
//                }
//            }
//        }
//        waveNumber++;
//        if (!expanded || found) break;
//    }
//}
//
//// Нахождение обратного пути
//void restorePathMarks(int wave[N][N], int path_marks[N][N], int startX, int startY, int finishX, int finishY) {
//    // init
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < N; j++)
//            path_marks[i][j] = 0;
//
//    int x = finishX, y = finishY;
//    int distance = wave[x][y];
//
//    if (distance < 0) {
//        // unreachable
//        return;
//    }
//
//    int dx[4] = { -1, 1, 0, 0 };
//    int dy[4] = { 0, 0, -1, 1 };
//
//    while (distance > 0) {
//        int moved = 0;
//        for (int k = 0; k < 4; k++) {
//            int nx = x + dx[k];
//            int ny = y + dy[k];
//            if (nx >= 0 && nx < N && ny >= 0 && ny < N && wave[nx][ny] == distance - 1) {
//                // mark (nx,ny) as path (don't mark start/sfinish here explicitly)
//                path_marks[nx][ny] = 1;
//                x = nx; y = ny;
//                distance--;
//                moved = 1;
//                break;
//            }
//        }
//        if (!moved) break; // safety
//    }
//}
//
//int main() {
//    init_rng();
//
//    int field[N][N];
//    int wave[N][N];
//    int path_marks[N][N];
//    int startX, startY, finishX, finishY;
//    int obstacles;
//
//    printf("Enter number of obstacles: ");
//    if (scanf("%d", &obstacles) != 1) return 0;
//
//    generateField(field, obstacles, &startX, &startY, &finishX, &finishY);
//
//    printf("Start: (%d, %d)\n", startX, startY);
//    printf("Finish: (%d, %d)\n\n", finishX, finishY);
//
//    printInitialField(field);
//
//    // propagate wave (no intermediate prints)
//    wavePropagation(field, wave, startX, startY, finishX, finishY);
//
//    // print the final wave matrix with distances
//    printWaveMatrix(wave);
//
//    // recover path (marks)
//    restorePathMarks(wave, path_marks, startX, startY, finishX, finishY);
//
//    // print final path overlay
//    printFinalPath(field, startX, startY, finishX, finishY, path_marks);
//
//    // If finish unreachable, notify user
//    if (wave[finishX][finishY] < 0)
//        printf("No path found from Start to Finish.\n");
//    else
//        printf("Path length (distance): %d\n", wave[finishX][finishY]);
//
//    return 0;
//}
