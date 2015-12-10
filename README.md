# SOI, lab 4 (monitory)
Bufor 9 elementowy FIFO. Dwóch konsumentów i dwóch producentów. Producenci produkują liczby całkowite. Producent A może zapisywać elementy do bufora jedynie gdy ich suma w buforze będzie mniejsza niż 20. Odczyt (usunięcie) jest dozwolone, gdy liczba elementów w buforze jest większa niż 3.

## Użycie
```
> make
> ./soi4
```
