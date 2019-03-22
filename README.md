# fabric-of-spacetime
Documentation for mechatronic art project.

The Fabric of Spacetime is an installation serving as an interactive model of a young universe, combining crochet and electronics to create a dynamic and luminescent experience.

The main physical component is a large hand crocheted hyperbolic manifold, where stitches were added at an exponential rate.  In this way, the circumference grows exponentially faster than the length, introducing negative curvature and resulting in the many folds (this technique was pioneered in 1997 by Dr. Daina Taimina, a mathematician at Cornell).  This curvature is analogous to the geometry of a very young universe (much less than one second old), where the spacial dimensions grew exponentially with respect to the time dimension, introducing curvature in the geometry of spacetime itself.  This crocheted piece is almost 10 pounds of yarn, with the circumference at the bottom being in excess of 75 feet.

Sewed into the fabric model are 264 individually programmable neopixel LEDs, forming a spiral pattern around the inside, and mounted throughout room are 6 servo motors, each connected by fishing wire to a fold in the crocheted model.  There is also a PIR motion sensor directed toward the underbelly of the piece.  All of these are wired to an Arduino MEGA microcontroller, and powered by 5 volts and 3 amps of electricity.

While undisturbed, the servos pull the model open and closed in a regular breathing motion, shifting to red while opening, and to blue while closing.  This is an homage to the relativist doppler effect, or cosmic red shift and blue shift of the universe.  Indeed, since red has the longest wavelength of the visible spectrum, things moving away from us at relativistic velocities gain a slight red tint in color, and the same can be said for things moving towards us but blue.  Thus as the color shift of the piece represents the actual shift that would be visible in an expanding and contracting universe.

When one walks under the piece, chaos is introduced, and the motion sensor triggers one of 5 different patterns in the movement and lights, ranging from relatively controlled to completely random, until finally entropy kicks in and the universe returns to its (semi-)stable breathing state.

Enjoy the images and video and feel free to study the arduino code and circuit diagrams linked in this repository.  If you would like more information or to make any suggestions please don't hesitate to contact me at gdorfsmanhopkins@gmail.com.
