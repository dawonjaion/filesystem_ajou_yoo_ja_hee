#include <stdio.h>

int max(int n[]){
    int tmp = 0;
    for (int i = 1; i < 5; i++){
        if (n[tmp]<n[i]) tmp = i;
    }
    return n[tmp];
}

int min(int n[]){
    int tmp = 0;
        for (int i = 1; i < 5; i++){
            if (n[tmp]>n[i]) tmp = i;
        }
        return n[tmp];
}

double average(int n[]){
    double sum = 0;
    for (int i = 0; i < 6; i++){
        sum += n[i];
    }
    return sum/6;
}

double dispertion(double ave, int n[]){
    double dev[6];
    double sum = 0;
    for (int i = 0; i < 6; i++){
        dev[i] = n[i] - ave;
    }

    for (int i = 0; i < 6; i++){
        dev[i] *= dev[i];
        sum += dev[i];
    }

    return sum / 6;

}

int main(){
    int n[6] = {19, 2, 25, 92, 36, 45};
    printf("  저장된 원소 \t: ");
    for (int i = 0; i < 6; i++){
        printf("%d  ", n[i]);
    }
    printf("\n");

    printf("    최솟값 \t: %d\n", min(n));
    printf("    최댓값 \t: %d\n", max(n));
    double ave = average(n);
    printf("     평균 \t: %f\n", ave);
    printf("     분산 \t: %f\n", dispertion(ave, n));
    
    return 0;
}