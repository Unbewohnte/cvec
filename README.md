# CVEC - C vector
### "Reinventing the bicycle"-class C vector library

## Usage

The values are stored internally in vector's `contents` as `char`s so any types fit, but only one type per vector should be used. It is your responsibility to not use different types in one vector.   

The overall usage should be done via shipped cvec_* functions, but in case of the need for some pointer math magic, all necessary fields are there for your usage.

This snippet should give you the general idea of usage.

```c
cvec vec = cvec_new(sizeof(size_t), 1);
size_t val = 0x15dc;
cvec_put(&vec, &val);
printf("sizeof(size_t) -> %zu\n", sizeof(size_t));
printf("%s; size %zu\n", vec.contents, vec.size);
val = 0x02ec;
cvec_put(&vec, &val);
printf("After realloc: %s; size: %zu\n", vec.contents, vec.size);
printf("At index %d: %zx\n", 1, *(size_t*) cvec_at(&vec, 1));
cvec_free(&vec);
```

## License
MIT