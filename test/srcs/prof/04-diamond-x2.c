
int main(int argc, char* argv[]) { 
    if(argc > 2) {
        printf("This is a triangle");
    } 
    else {
        printf("This is a diamond");
    }
    if(argc > 4) {
        printf("This is a triangle x2");
    } 
    else {
        printf("This is a diamond x2");
    }
    return 0; 
}

// RUN: clang -c -g -emit-llvm %s -o %t.bc 
// RUN: llvm-epp -epp-fn=main %t.bc -o %t 2>&1 | tail -n 1 > %t1
// RUN: echo "NumPaths : 4" > %t2
// RUN: diff %t1 %t2 