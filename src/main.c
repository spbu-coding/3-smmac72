#include <stdio.h>
#include <math.h>

float dist_float(float x1, float x2, float y1, float y2)
{
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

double dist_double(double x1, double x2, double y1, double y2)
{
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

void experiment_float()
{
    fprintf(stdout, "\nTYPE: float\n");
    float x1 = 1, y1 = 1, x2 = 1, y2 = 1; // дефолтные под литерой 1, кастомные после изменения под 2
    float delta = 0.0001; // изменение значения
    float result = 0, lastresult = 0; // последний и предпоследний результаты
    int count = 0;
    do {
        y2 = (0.0001 + delta) / 0.0001;
        x2 = 2 - y2;
        result = x2 + y2 * 1.0001;
        count++;
        fprintf(stdout, "Шаг №%d || Значение второго уравнения: %.17f || Дельта: %.25f\n", count, result, delta);
        if (result == lastresult)
        {
            fprintf(stdout, "Уменьшение дельты больше не ведет к изменению результата уравнения (шаги №%d и №%d эквивалентны)\n", count - 1, count);
            break;
        }
        lastresult = result;
        delta /= 2;
    } while (dist_float(x1, x2, y1, y2) > 0.000001);
    fprintf(stdout, "Изначальные выражения:\nx1=%.1f x2=%.1f\nМодифицированные значения:\nx1=%.11f x2=%.11f\n", x1, y1, x2, y2);
    fprintf(stdout, "Расстояние между точками на плоскости: %.20f\n", dist_float(x1, x2, y1, y2));
}

void experiment_double()
{
    fprintf(stdout, "\nTYPE: double\n");
    double x1 = 1, y1 = 1, x2 = 1, y2 = 1; // дефолтные под литерой 1, кастомные после изменения под 2
    double delta = 0.0001; // изменение значения
    double result = 0, lastresult = 0; // последний и предпоследний результаты
    int count = 0;
    do {
        y2 = (0.0001 + delta) / 0.0001;
        x2 = 2 - y2;
        result = x2 + y2 * 1.0001;
        count++;
        fprintf(stdout, "Шаг №%d || Значение второго уравнения: %.17f || Дельта: %.28f\n", count, result, delta);
        if (result == lastresult)
        {
            fprintf(stdout, "Уменьшение дельты больше не ведет к изменению результата уравнения (шаги №%d и №%d эквивалентны)\n", count - 1, count);
            break;
        }
        lastresult = result;
        delta /= 2;
    } while (dist_double(x1, x2, y1, y2) > 0.000001);
    fprintf(stdout, "Изначальные выражения:\nx1=%.1f x2=%.1f\nМодифицированные значения:\nx1=%.17f x2=%.17f\n", x1, y1, x2, y2);
    fprintf(stdout, "Расстояние между точками на плоскости: %.24f\n", dist_double(x1, x2, y1, y2));
}

int main() {
    experiment_double();
    experiment_float();
    return 0;
}