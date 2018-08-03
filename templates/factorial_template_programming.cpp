template<unsigned int i>
unsigned int factorial()
{
    return i*factorial<i-1>();
}

template<>
unsigned int factorial<0>()
{
    return 1;
}

int main() {
    unsigned int i = factorial<5>();
    return 0;
}