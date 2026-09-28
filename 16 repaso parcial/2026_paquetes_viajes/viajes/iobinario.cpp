#include "IOBinario.h"

void escribirString(std::ostream& out, const std::string& s) {
    size_t len = s.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(s.data(), static_cast<std::streamsize>(len));
}

std::string leerString(std::istream& in) {
    size_t len = 0;
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    std::string s(len, '\0');
    if (len > 0) {
        in.read(&s[0], static_cast<std::streamsize>(len));
    }
    return s;
}
