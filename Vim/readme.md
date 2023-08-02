# Using vim

### Modes

**normal** - We can change to this mode by pressing the **"esc"** key in insert mode
**insert** - We can change to this mode by pressing the **"i"** or **"a"** key in insert mode
**visual** - We can change to this mode by pressing the **"v"** key in normal mode. 

### File management commands

**`:q`** - close wim.
**`:q!`** - close vim without saving changes.
**`:w`** - save changes.
**`:wq`** or **`:x`** - save changes and close vim.

### Movement command

**`gg`** - move to the top of file
**`GG`** - move to the end of file
**`{number} + gg`** or **`{number} + G`** - moves to line
arrow **`↑`** or **`k`** - move line up
arrow **`↓`** or **`j`** - move line down
arrow **`→`** or **`l`** - move one char right
arrow **`←`** or **`h`** - move one char left
**`{number} + {movement command}`** - moves x times for example: **`23 →`** moves 23 chars right

### Text operations

**`dd`** - delete line
**`yy`** - copy line
**`p`** - paste line under cursor
**`P`** - paste line in the same line that is cursor
**`u`** - undo changes
**`Ctrl + r`**  - redo changes
you can combine this operations with movement for example **d3j** delete 3 lines of code from cursor to down

### Text operations in visual mode

**`d`** - delete selected text
**`y`** - copy selected text
**`shift + i`** - insert in all selected places

### Finding in text

**`/ {text}`** or **`? {text}`** - finding in file text.
**`n`** - move to next found element.
**`N`** - move to prev found element.
**`:%s/{old}/{new}/g`** - replace old phrase with new phrase in file