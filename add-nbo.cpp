#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>

void usage(){
    printf("syntax:  add-nbo <file1> <file2>\n");
    printf("sample:  add-nbo a.bin c.bin\n");
}

uint32_t addnbo(char* file) {
    FILE* fp = fopen(file, "rb");
    uint32_t n;
    size_t fileLen = fread(&n, 1, sizeof(n), fp);
    if (fileLen != sizeof(n)) {
        fprintf(stderr, "Error read Input file");
        exit(-1);
    }
    n = ntohl(n);
    fclose(fp);
    return n;
}

int main(int argc, char* argv[]) {
    if (argc != 3){
        usage();
        exit(-1);
    }
    uint32_t num1 = addnbo(argv[1]);
    uint32_t num2 = addnbo(argv[2]);
    int result = num1+num2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, result, result);

    return 0;
}
