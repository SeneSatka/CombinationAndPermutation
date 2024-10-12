#include <iostream>
using namespace std;
unsigned long int Factorial(int n)
{
    if (n > 1)
    {
        return n * Factorial(n - 1); // Gelen sayıyı bir eksiğinin faktöriyeli ile çarpar.
    }
    return 1; // Gelen sayı 1 ya da 1 den küçükse geriye 1 döndürür.
}
unsigned long int Permutation(int n, int r)
{
    unsigned long int result = 1;
    for (int i = 0; i < r; i++)
    {
        result *= (n - i); // Permütason formülüne göre n*(n-1)*....*(n-r+1) işlemini yapar.
    }
    return result;
}
unsigned long int Combination(int n, int r)
{
    if (r > (n / 2))
        r = n - r;                           // Gelen r n sayısının yarısından büyükse r yi n olan uzaklığına eşitler.
    return Permutation(n, r) / Factorial(r); // Kombinasyon formülüne göre P(n,r)/r! işlemini döndürür.
}
int main(int, char **)
{
    int op, n1, n2;
    unsigned long int result;
q: // Geri dönüş noktası oluşturur.
    cout << "1. Combination\n2. Permutation\n3. Factorial\n>>";
    cin >> op;
    if (op < 1 || op > 3) // İşlem girdisi 1 ,2 veya 3 değilse alttaki kodlar çalışır.
    {
        cout << "Wrong operation. Operation must be 1 or 2 or 3" << endl;
        goto q; // Geri dönüş noktasına döner.
    }
    cout << "Number: ";
    cin >> n1;
    if (op != 3)
    {
        cout << "Number: ";
        cin >> n2;
    }
    if (op == 1)
        result = Combination(n1, n2);
    else if (op == 2)
        result = Permutation(n1, n2);
    else
        result = Factorial(n1);
    cout << "Result: " << result;
}
