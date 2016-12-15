# Permute

A simple permutation generator.

## Installation
```sh
git clone https://github.com/eldrewolf/permute
cd permute
make
sudo make install

```
## Usage
### Standard Permutations
```sh
permute abc

<<output
abc
bac
cab
acb
bca
cba
output
```

### Permutations with repetition
```sh
permute -n2 abc

<<output
aa
ba
ca
ab
bb
cb
ac
bc
cc
output
```

## Todo
1. Implement k-permutaions
2. Implement multiset permutations

## License

Permute is free software. You are free to redistribute it and/or modify it under the terms of the GNU Lesser General Public License Version 3 (LGPLv3) as published by the Free Software Foundation
See the [LICENSE](LICENSE.md) file for license rights and limitations (LGPLv3).
