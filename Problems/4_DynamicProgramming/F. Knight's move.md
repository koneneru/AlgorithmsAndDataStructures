## Ход конём
ограничение по времени на тест: 1 секунда  
ограничение по памяти на тест: 64 мегабайта  
ввод: стандартный ввод  
вывод: стандартный вывод

Дана прямоугольная доска ***N*** *×* ***M*** (***N*** строк и ***M*** столбцов).
В левом верхнем углу находится шахматный конь, которого необходимо переместить
в правый нижний угол доски.

![Sample](https://statement.bacs.cs.istu.ru/statement/get/CjdiYWNzL3Byb2JsZW0vYm5pY2swNTctdXBkYXRlZC9zdGF0ZW1lbnQvdmVyc2lvbnMvQy9odG1sEgYKBFYK84A/bacs/MqZZNxIJrMrGbo5KCUiOVsMhSDpA2zOh8wIY0xVYNcm3a31AGLBBRKOh0NhEuVitOiCjlCITq77__BORHuRS-PnQ3L2B4TpQ-vgWcsUUKjR5H2JGq-D6yktPN51eESCTOmKMMa2B9aSxmMVFUmXQ8wVGRPLyVbf-H5VX9xSksTLrz6Sy-ZjGiK_tl5ovtSt-tiXZNRjX5CedTUVB8rg6FNTT6D1FaZoppghwl66iiJg9tvvhQYcLUzes_wJSCF7UB622QGjC_ndlcV6aRSkde88HMoN6NCZH1buwbMHQMYXcj7xvrgi8easCBcOSoOEQn4ijVUXh3I4KUK0K9EefbQ/5af320b41c3bb55d96e9786435ae16a59c3b96f9.png)

При этом конь может ходить либо на **2** клетки вправо и **1** клетку вниз, либо
на **2** клетки вниз и **1** клетку вправо.

Необходимо определить, сколько существует различных маршрутов, ведущих из левого
верхнего угла в правый нижний угол.

## Входные данные
В единственной строке входного файла находятся два натуральных числа ***N*** и
***M*** (**1** ⩽ ***N***, ***M*** ⩽ **50**).

## Выходные данные
Выведите единственной число — количество способов добраться конём до правого
нижнего угла доски.

## Примеры
**Входные данные**
```no-hilights
3 2
```
**Выходные данные**
```no-hilights
1
```
**Входные данные**
```no-hilights
31 34
```
**Выходные данные**
```no-hilights
293930
```
