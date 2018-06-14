#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <emscripten.h>

int main() {
    EM_ASM({
        Module['canvas'].style['cursor'] = 'pointer';
    });
}
