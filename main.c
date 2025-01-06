#include <termios.h>
#include <unistd.h>

int main(){
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);

    term.c_cc[VEOF] = 2; //Change te EOF to Ctrl+ B(ASCII 2)
    term.c_cc[VINTR] = _POSIX_VDISABLE;//Disable INTR by setting it to _POSIX_VDISABLE

    tcsetattr(STDIN_FILENO,TCSAFLUSH,&term);

    return 0;

}