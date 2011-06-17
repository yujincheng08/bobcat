#include <iostream>
#include <fstream>
#include <bobcat/errno>
#include <bobcat/decryptbuf>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc == 1)
        throw Errno("1st arg: method, 2nd arg: key, 3rd arg: file to "
                    "decrypt (to stdout), 4th arg: iv");

    cerr << "Key: `" << argv[2] << "'\n"
            "IV:  `" << argv[4] << "'\n";

    DecryptBuf decryptbuf(cout, argv[1], argv[2], argv[4]);
    ostream out(&decryptbuf);
    ifstream in(argv[3]);

    out << in.rdbuf();
    // decryptbuf.done();       // optionally
}
catch(Errno const &err)
{
    cout << err.why() << endl;
    return 1;
}





