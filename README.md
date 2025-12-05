[ft_printf_README.md](https://github.com/user-attachments/files/23966987/ft_printf_README.md)
# 🖨️ ft_printf

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/School-42%20Lausanne-black?style=for-the-badge" alt="42"/>
  <img src="https://img.shields.io/badge/Grade-125%2F100-brightgreen?style=for-the-badge" alt="Grade"/>
  <img src="https://img.shields.io/badge/Norminette-Passing-success?style=for-the-badge" alt="Norm"/>
</p>

<p align="center">
  <a href="#-english">🇬🇧 English</a> | <a href="#-français">🇫🇷 Français</a>
</p>

---

# 🇬🇧 English

<details open>
<summary><b>Click to expand/collapse English version</b></summary>

## 📖 About

**ft_printf** is a project from the 42 school curriculum that challenges students to recreate the standard C library function `printf()`. This project deepens understanding of variadic functions, formatted output, and low-level string manipulation.

The implementation handles multiple format specifiers and produces output identical to the original `printf()` function.

---

## ✨ Features

### Supported Format Specifiers

| Specifier | Description | Example |
|-----------|-------------|---------|
| `%c` | Single character | `ft_printf("%c", 'A')` → `A` |
| `%s` | String | `ft_printf("%s", "Hello")` → `Hello` |
| `%p` | Pointer address (hex) | `ft_printf("%p", ptr)` → `0x7fff5fbff8c8` |
| `%d` | Signed decimal integer | `ft_printf("%d", -42)` → `-42` |
| `%i` | Signed integer | `ft_printf("%i", 42)` → `42` |
| `%u` | Unsigned decimal integer | `ft_printf("%u", 42)` → `42` |
| `%x` | Hexadecimal (lowercase) | `ft_printf("%x", 255)` → `ff` |
| `%X` | Hexadecimal (uppercase) | `ft_printf("%X", 255)` → `FF` |
| `%%` | Percent sign | `ft_printf("%%")` → `%` |

### Additional Features

- ✅ Full **libft** integration (50+ utility functions)
- ✅ Linked list support
- ✅ Memory-safe implementation
- ✅ Handles `NULL` strings and pointers gracefully
- ✅ Returns the number of characters printed

---

## 📁 Project Structure

```
ft_printf/
├── 📂 include/
│   ├── ft_printf.h          # ft_printf function prototypes
│   └── libft.h              # libft function prototypes
├── 📂 srcs/
│   ├── ft_printf.c          # Main printf implementation
│   ├── parse.c              # Format specifier parsing
│   ├── ft_print_char.c      # Character & string output
│   ├── ft_print_int.c       # Integer & hex output
│   ├── ft_print_void.c      # Pointer address output
│   └── [40+ libft files]    # Complete libft library
├── 📂 obj/                   # Object files (generated)
└── Makefile                  # Build automation
```

---

## 🛠️ Installation & Usage

### Compilation

```bash
# Clone the repository
git clone https://github.com/yourusername/ft_printf.git
cd ft_printf

# Compile the library
make

# Clean object files
make clean

# Full clean (remove library too)
make fclean

# Recompile everything
make re
```

### Using in Your Project

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    // Basic usage
    ft_printf("Hello, %s!\n", "World");
    
    // Multiple specifiers
    ft_printf("Char: %c, String: %s, Int: %d\n", 'A', "test", 42);
    
    // Hexadecimal
    ft_printf("Hex lower: %x, Hex upper: %X\n", 255, 255);
    
    // Pointer address
    int num = 42;
    ft_printf("Address: %p\n", &num);
    
    // Return value (character count)
    count = ft_printf("This has %d characters\n", 25);
    ft_printf("Printed %d characters\n", count);
    
    return (0);
}
```

### Compiling with ft_printf

```bash
gcc -Wall -Wextra -Werror your_program.c -L. -lft -I include/ -o program
```

---

## 🔧 Technical Implementation

### How ft_printf Works

```
ft_printf("Hello %s, you are %d years old", name, age)
         │
         ▼
    ┌─────────────┐
    │  Parse      │ ──► Scan string for '%' characters
    │  Format     │
    └─────────────┘
         │
         ▼
    ┌─────────────┐
    │  Identify   │ ──► Match specifier (s, d, x, etc.)
    │  Specifier  │
    └─────────────┘
         │
         ▼
    ┌─────────────┐
    │  Extract    │ ──► Use va_arg to get argument
    │  Argument   │
    └─────────────┘
         │
         ▼
    ┌─────────────┐
    │  Convert &  │ ──► Apply appropriate conversion
    │  Output     │
    └─────────────┘
         │
         ▼
    Return total characters printed
```

### Variadic Functions

The project uses C's variadic function mechanism:

```c
#include <stdarg.h>

int ft_printf(const char *str, ...)
{
    va_list arg;
    
    va_start(arg, str);      // Initialize argument list
    // ... process arguments with va_arg(arg, type)
    va_end(arg);             // Clean up
    
    return (len);
}
```

---

## 🧪 Testing

```bash
# Create a test file
cat << 'EOF' > test.c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ft_ret, std_ret;
    
    printf("=== Testing ft_printf ===\n\n");
    
    // Test strings
    ft_ret = ft_printf("ft_printf: %s\n", "Hello World");
    std_ret = printf("printf:    %s\n", "Hello World");
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);
    
    // Test integers
    ft_ret = ft_printf("ft_printf: %d %i\n", -42, 2147483647);
    std_ret = printf("printf:    %d %i\n", -42, 2147483647);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);
    
    // Test hex
    ft_ret = ft_printf("ft_printf: %x %X\n", 255, 255);
    std_ret = printf("printf:    %x %X\n", 255, 255);
    printf("Returns: ft=%d, std=%d\n\n", ft_ret, std_ret);
    
    return (0);
}
EOF

# Compile and run
gcc -Wall -Wextra -Werror test.c -L. -lft -I include/ -o test
./test
```

---

## 📝 42 Norm Compliance

All code follows the **42 Norm** (Norminette v3):

- ✅ Max 25 lines per function
- ✅ Max 80 characters per line
- ✅ Max 4 parameters per function
- ✅ Max 5 variables per function
- ✅ Only `while` loops (no `for`)
- ✅ Proper header format

</details>

---

# 🇫🇷 Français

<details>
<summary><b>Cliquez pour déplier/replier la version française</b></summary>

## 📖 À propos

**ft_printf** est un projet du cursus de l'école 42 qui met au défi les étudiants de recréer la fonction standard `printf()` de la bibliothèque C. Ce projet approfondit la compréhension des fonctions variadiques, de la sortie formatée et de la manipulation de chaînes bas niveau.

L'implémentation gère plusieurs spécificateurs de format et produit une sortie identique à la fonction `printf()` originale.

---

## ✨ Fonctionnalités

### Spécificateurs de Format Supportés

| Spécificateur | Description | Exemple |
|---------------|-------------|---------|
| `%c` | Caractère unique | `ft_printf("%c", 'A')` → `A` |
| `%s` | Chaîne de caractères | `ft_printf("%s", "Hello")` → `Hello` |
| `%p` | Adresse pointeur (hex) | `ft_printf("%p", ptr)` → `0x7fff5fbff8c8` |
| `%d` | Entier décimal signé | `ft_printf("%d", -42)` → `-42` |
| `%i` | Entier signé | `ft_printf("%i", 42)` → `42` |
| `%u` | Entier décimal non signé | `ft_printf("%u", 42)` → `42` |
| `%x` | Hexadécimal (minuscules) | `ft_printf("%x", 255)` → `ff` |
| `%X` | Hexadécimal (majuscules) | `ft_printf("%X", 255)` → `FF` |
| `%%` | Signe pourcentage | `ft_printf("%%")` → `%` |

### Fonctionnalités Additionnelles

- ✅ Intégration complète de **libft** (50+ fonctions utilitaires)
- ✅ Support des listes chaînées
- ✅ Implémentation sécurisée en mémoire
- ✅ Gestion gracieuse des chaînes et pointeurs `NULL`
- ✅ Retourne le nombre de caractères imprimés

---

## 📁 Structure du Projet

```
ft_printf/
├── 📂 include/
│   ├── ft_printf.h          # Prototypes ft_printf
│   └── libft.h              # Prototypes libft
├── 📂 srcs/
│   ├── ft_printf.c          # Implémentation principale
│   ├── parse.c              # Parsing des spécificateurs
│   ├── ft_print_char.c      # Sortie caractères & chaînes
│   ├── ft_print_int.c       # Sortie entiers & hex
│   ├── ft_print_void.c      # Sortie adresses pointeur
│   └── [40+ fichiers libft] # Bibliothèque libft complète
├── 📂 obj/                   # Fichiers objets (générés)
└── Makefile                  # Automatisation de build
```

---

## 🛠️ Installation & Utilisation

### Compilation

```bash
# Cloner le dépôt
git clone https://github.com/yourusername/ft_printf.git
cd ft_printf

# Compiler la bibliothèque
make

# Nettoyer les fichiers objets
make clean

# Nettoyage complet (supprimer aussi la bibliothèque)
make fclean

# Tout recompiler
make re
```

### Utilisation dans Votre Projet

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    // Utilisation basique
    ft_printf("Bonjour, %s!\n", "Monde");
    
    // Spécificateurs multiples
    ft_printf("Char: %c, String: %s, Int: %d\n", 'A', "test", 42);
    
    // Hexadécimal
    ft_printf("Hex min: %x, Hex maj: %X\n", 255, 255);
    
    // Adresse pointeur
    int num = 42;
    ft_printf("Adresse: %p\n", &num);
    
    // Valeur de retour (compte de caractères)
    count = ft_printf("Ceci a %d caractères\n", 25);
    ft_printf("Imprimé %d caractères\n", count);
    
    return (0);
}
```

### Compiler avec ft_printf

```bash
gcc -Wall -Wextra -Werror votre_programme.c -L. -lft -I include/ -o programme
```

---

## 🔧 Implémentation Technique

### Comment ft_printf Fonctionne

```
ft_printf("Bonjour %s, tu as %d ans", nom, age)
         │
         ▼
    ┌─────────────┐
    │  Parser     │ ──► Scanner la chaîne pour les '%'
    │  Format     │
    └─────────────┘
         │
         ▼
    ┌─────────────┐
    │  Identifier │ ──► Matcher le spécificateur (s, d, x, etc.)
    │  Spécif.    │
    └─────────────┘
         │
         ▼
    ┌─────────────┐
    │  Extraire   │ ──► Utiliser va_arg pour obtenir l'argument
    │  Argument   │
    └─────────────┘
         │
         ▼
    ┌─────────────┐
    │  Convertir  │ ──► Appliquer la conversion appropriée
    │  & Sortie   │
    └─────────────┘
         │
         ▼
    Retourner le total de caractères imprimés
```

### Fonctions Variadiques

Le projet utilise le mécanisme de fonctions variadiques du C :

```c
#include <stdarg.h>

int ft_printf(const char *str, ...)
{
    va_list arg;
    
    va_start(arg, str);      // Initialiser la liste d'arguments
    // ... traiter les arguments avec va_arg(arg, type)
    va_end(arg);             // Nettoyer
    
    return (len);
}
```

---

## 🧪 Tests

```bash
# Créer un fichier de test
cat << 'EOF' > test.c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ft_ret, std_ret;
    
    printf("=== Test de ft_printf ===\n\n");
    
    // Test chaînes
    ft_ret = ft_printf("ft_printf: %s\n", "Bonjour Monde");
    std_ret = printf("printf:    %s\n", "Bonjour Monde");
    printf("Retours: ft=%d, std=%d\n\n", ft_ret, std_ret);
    
    // Test entiers
    ft_ret = ft_printf("ft_printf: %d %i\n", -42, 2147483647);
    std_ret = printf("printf:    %d %i\n", -42, 2147483647);
    printf("Retours: ft=%d, std=%d\n\n", ft_ret, std_ret);
    
    // Test hex
    ft_ret = ft_printf("ft_printf: %x %X\n", 255, 255);
    std_ret = printf("printf:    %x %X\n", 255, 255);
    printf("Retours: ft=%d, std=%d\n\n", ft_ret, std_ret);
    
    return (0);
}
EOF

# Compiler et exécuter
gcc -Wall -Wextra -Werror test.c -L. -lft -I include/ -o test
./test
```

---

## 📝 Conformité Norme 42

Tout le code respecte la **Norme 42** (Norminette v3) :

- ✅ Max 25 lignes par fonction
- ✅ Max 80 caractères par ligne
- ✅ Max 4 paramètres par fonction
- ✅ Max 5 variables par fonction
- ✅ Uniquement boucles `while` (pas de `for`)
- ✅ Format d'en-tête correct

</details>

---

## 👤 Author / Auteur

**fducrot** - 42 Lausanne Student / Étudiant 42 Lausanne

[![GitHub](https://img.shields.io/badge/GitHub-fducrot-181717?style=flat-square&logo=github)](https://github.com/fducrot)

---

## 📄 License

This project is part of the 42 school curriculum. Feel free to use it as a reference, but please don't copy it directly for your own 42 projects.

---

<p align="center">
  <i>🇬🇧 "Because sometimes you just need to printf your own way."</i>
  <br><br>
  <i>🇫🇷 "Parce que parfois, il faut juste printf à sa manière."</i>
</p>

---

<p align="center">
  Made with ❤️ at 42 Lausanne
</p>
