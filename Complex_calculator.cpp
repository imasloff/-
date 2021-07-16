#include <stdio.h>

typedef struct Complex
{
    int Re;
    int Im;
} comp;

comp sum(comp z1, comp z2)
{
    comp res;
    res.Re = z1.Re + z2.Re;
    res.Im = z1.Im + z2.Im;
    return res;
}

comp sub(comp z1, comp z2)
{
    comp res;
    res.Re = z1.Re - z2.Re;
    res.Im = z1.Im - z2.Im;
    return res;
}

comp mult(comp z1, comp z2)
{
    comp res;
    res.Re = z1.Re * z2.Re - z1.Im * z2.Im;
    res.Im = z1.Re * z2.Im + z2.Re * z1.Im;
    return res;
}

comp div(comp z1, comp z2)
{
    comp res;
    res.Re = (z1.Re * z2.Re + z1.Im * z2.Im) / (z2.Re * z2.Re + z2.Im * z2.Im);
    res.Im = (z2.Re * z1.Im - z1.Re * z2.Im) / (z2.Re * z2.Re + z2.Im * z2.Im);
    return res;
}

int main()
{
    comp z1, z2;
    char op = ' ';
    printf("Enter z1.Re: ");
    scanf_s("%d", &z1.Re);
    printf("Enter z1.Im: ");
    scanf_s("%d", &z1.Im);
    getchar();
    printf("Enter the operation: ");
    scanf_s("%c", &op, 1);
    printf("Enter z2.Re: ");
    scanf_s("%d", &z2.Re);
    printf("Enter z2.Im: ");
    scanf_s("%d", &z2.Im);
    switch (op)
    {
    case '+': printf("= %d + %di", sum(z1, z2).Re, sum(z1, z2).Im); break;
    case '-': printf("= %d + %di", sub(z1, z2).Re, sub(z1, z2).Im); break;
    case '*': printf("= %d + %di", mult(z1, z2).Re, mult(z1, z2).Im); break;
    case '/': printf("= %d + %di", div(z1, z2).Re, div(z1, z2).Im); break;
    default: printf("Error! Invalid operation!"); break;
    }
}
