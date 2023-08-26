#include<stdio.h>

char c;
int answer = 0;
int sum = 0;

int main() {
    
    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    while(scanf("%c", &c) != EOF) {
        if (c == '\n') {
            if (sum % 3 == 0) {
                answer++;
            }
            sum = 0;
        } else {
            sum += c - '0';
        }
    }

    printf("%d\n", answer);

    return 0;
}
