# planck-keymap

This repository contains my [planck light](https://drop.com/buy/massdrop-x-olkb-planck-light-mechanical-keyboard) keymap.

To try this keymap out on your board, set up qmk_firmware on your system as per the [guide](https://docs.qmk.fm/#/newbs_getting_started), then, while in the `qmk_firmware` directory, run the following commands:

```bash
git submodule add https://github.com/mtoohey31/crkbd-keymap ./keyboards/planck/keymaps/mtoohey31
qmk compile -kb planck/light -km mtoohey31
```

ghis keymap should also work on other planck versions, though it hasn't been tested on them.
