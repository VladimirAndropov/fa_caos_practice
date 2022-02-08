# 11 Семинар 08.02.2022 mmap/fork

## Файлики с кодом:

* [Пример работы mmap](mmap_example.c)



# mmap

```
#include <sys/mman.h>

void *mmap(
    void *addr,    /* рекомендуемый адрес отображения */
    size_t length, /* размер отображения */
    int prot,      /* аттрибуты доступа */
    int flags,     /* флаги совместного отображения */
    int fd,        /* файловый дескриптор файла */
    off_t offset   /* смещение относительно начала файла */
  );

int munmap(void *addr, size_t length) /* освободить отображение */

```

При ошибке `mmap` возвращает специальное значение `MAP_FAILED`.
Чтобы детектировать ошибку, нужно проверять возвращаемое значение не на `NULL`,
а на `MAP_FAILED`

## Значения prot:

	 PROT_NONE   Pages may not be accessed.
     PROT_READ   Pages may be read.
     PROT_WRITE  Pages may be written.
     PROT_EXEC   Pages may be executed.

Использовать с битовым или: `PROT_READ | PROT_WRITE`

## Значения flags:
* `MAP_FIXED` - требует, чтобы память была выделена по указаному в первом аргументе адресу; без этого флага ядро может выбрать адрес, наиболее близкий к указанному.
* `MAP_ANONYMOUS` - выделить страницы в оперативной памяти, а не связать с файлом.
* `MAP_SHARED` - выделить страницы, разделяемые с другими процессами; в случае с отображением на файл - синхронизировать изменения так, чтобы они были доступны другим процессам.
* `MAP_PRIVATE` - в противоположность `MAP_SHARED`, не делать отображение доступным другим процессам. В случае отображения на файл, он доступен для чтения, а созданные процессом изменения, в файл не сохраняются.




# References:

* [Лекция с физтеха] (https://github.com/victor-yacovlev/mipt-diht-caos/tree/master/practice/mmap)
* [Прошлый год](https://github.com/blackav/hse-caos-2020/tree/master/14-mmap)