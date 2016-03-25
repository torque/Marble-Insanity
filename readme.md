#### Marble Insanity

This is the source code for my Mechatronics I final project in Fall
2015.

The concept of the project was to build an "arcade" game. The specific
requirements were that it have a minimum of two actuators and two
sensors, that it be activated by dropping a penny through a slot, and
that a single "round" of the game last between 30 and 60 seconds.
Additionally, the game was required to be battery powered and able to
maintain continuous operation for over three hours. Students were given
the opportunity to work alone or in pairs. I elected to work alone, as
work on the project largely took place during Thanksgiving break, and I
didn't want to have to coordinate with someone over vacation.

To meet the requirements, I designed, fabricated, and assembled a
variety of parts into what I christened "Marble Insanity".

Mable Insanity consists of a 3D-printed pyramidal ramp structure mounted
on top of a square acrylic platform, which sits atop a 3D-printed cone.
Through two servos attached to adjacent edges, the player controls two
axes of tilt of the platform with a Wii Nunchuck. The goal is to roll a
ball up the ramp structure and reach the top within 30 seconds. The name
was inspired by Marble Madness, though the actual game plays more like
e.g. Monkey Ball.

Unfortunately, as a game, the project was not incredibly successful. The
amount of response lag between input and ball movement was large enough
that controlling the ball was borderline impossible, which was
exacerbated by the no-rail design of the ramp structure. Additionally,
there being only an absolute goal did not help to inspire a sense of
achievement in a round of gameplay. The ability to accrue multiple
points in a single round would probably have engaged players more
successfully.

[![Destructed model][image]][stl-model]

Models of all of the parts designed for this project are available
[in this repository][models].

#### Copyright

This code is not particularly general purpose or likely to be useful for
anything besides this project. Regardless, all the original code (i.e.
everything except `notes.h`)  in this project is licensed under the ISC
license, reproduced below.

```
Copyright (c) 2016, Scot Tomer

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
```

[image]: https://raw.githubusercontent.com/torque/marble-insanity-models/master/marble-insanity.png
[stl-model]: https://github.com/torque/marble-insanity-models/blob/master/marble-insanity.stl
[models]: https://github.com/torque/marble-insanity-models
