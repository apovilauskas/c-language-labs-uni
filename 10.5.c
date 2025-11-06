#include <stdio.h>
#include <assert.h>

void *memset(void *buffer, int ch, int size) {
    unsigned char *ptr = (unsigned char *)buffer;
    unsigned char value = (unsigned char)ch;
    
    for(int i = 0; i < size; i++) {
        ptr[i] = value;
    }
    return buffer;
}

int main() {
    
   
    char buf1[10]; // 1. Užpildyti char masyvą nuliais
    memset(buf1, 0, sizeof(buf1));
    for(int i = 0; i < 10; i++) {
        assert(buf1[i] == 0);
    }

    char buf2[10]; //2. Su A raide
    memset(buf2, 'A', sizeof(buf2));
    for(int i = 0; i < 10; i++) {
        assert(buf2[i] == 'A');
    }

    unsigned char buf3[10]; //3. Užpildyti 255
    memset(buf3, 255, sizeof(buf3));
    for(int i = 0; i < 10; i++) {
        assert(buf3[i] == 255);
    }


    unsigned char buf4[10]; //4. Užpildyti ne visus
    memset(buf4, 255, 3);
    for(int i = 0; i < 3; i++) {
        assert(buf4[i] == 255);
    }
    
    return 0;
}