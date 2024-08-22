# ziTester && MED-1337

![yoo](https://media1.tenor.com/m/oC_e7R9GvZ8AAAAC/rick-and-morty-rtj.gif)

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Overview

ZiTester is a tool designed to test and verify the status of exercise files for 42 School students. It runs shell scripts to check each exercise and updates the results accordingly.

## Features

- **File Existence Check**: Verifies if the exercise file exists.
- **Shell Script Execution**: Runs specific shell scripts to test each exercise.
- **Status Reporting**: Updates the status of each exercise based on the test results.

### Status Table

| key | value     |
|-----|-----------|
| OK  | passed    |
| KO  | FAILED    |
| NF  | NOT FOUND |

## Installation

* **FOR `zsh` :**

    ```sh
    zsh -c "$(curl -fsSL https://raw.githubusercontent.com/mirr-x/ziTester/main/bin/install.sh)"
    ```

* **FOR `bash` :**

    ```sh
    bash -c "$(curl -fsSL https://raw.githubusercontent.com/mirr-x/ziTester/main/bin/install.sh)"
    ```
## Usage

After installation, you can use ziTester to check your exercise files. Navigate to the directory containing your exercise files and run the following command:

```sh
zi [FOLDER NAME]
```

### Example

To test the folder C05, navigate to the directory containing the folder and run:

```sh
zi C05
```

### Instructions

```
     _ _____          _            
 ___(_)__   \___  ___| |_ ___ _ __ 
|_  / | / /\/ _ \/ __| __/ _ \ '__|
 / /| |/ / |  __/\__ \ ||  __/ |   
/___|_|\/   \___||___/\__\___|_|   
                                   
                                zi!


xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
                                                                          X
INSTRUCTIONS:                                                             X
                                                                          X
        • USAGE:                                                          X
            $ > zi [FOLDER NAME]                                          X
                                                                          X
        • EXAMPLE:                                                        X
            $ > zi C05                                                    X
                                                                          X
                                                                          X
--------------------------------------------------------------------------%
Made By: mirr-x              &&     Made By: mdbentaleb                   |
https://github.com/mirr-x    &&     https://github.com/mdbentaleb         |
--------------------------------------------------------------------------%
```