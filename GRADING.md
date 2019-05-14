### zar67

# Angry Birds Feedback
#### Your task was to create your own version of the class mobile game Angry Birds. 

![Angry Nerds](https://s11217.pcdn.co/wp-content/uploads/2011/04/angrynerds.jpg)

# Planning and Documentation
- [x] UML diagram present
- [ ] Algorithmic discussion of trajectory 

# Gameplay 

#### Basic Requirements: At Good Standard
- [ ] Introductory screen with instructions
- [x] Birds and Pigs rendered and positioned correctly
- [x] Click and drag support
- [x] Bird fires using player's origin
- [ ] Bird registers collisions with Pigs
- [x] Scoring system
- [x] Win and Lose states with replay options

#### Extended Functionality
- [x] Working extensions to the base requirements  
**Notes:** Level loading, physics and obstacles. 

# Implementation
- [x] Static Checks (within reason)
- [x] No memory leaks present
- [x] Correct use of the coding standard
- [x] Well structured and easy to follow
- [ ] Good use of object orientated design


# Marking

#### Breakdown of Components
Shown below are the weighting for each component being assessed. 

| Component                                        | %       |
| -------------------------------------------------|:-------:|
| Problem Analysis (UML, Pseudo-code & Flow-Chart) |   10%   |
| Playability & Innovation                         |   45%   |
| Technical Implementation                         |   45%   |
| ------                                           | ------- |
| **Total**                                        |**100%** | 

The three components total 100%. 
This assignment contributes **50%** of your portfolio mark. 

> You can find more information on breakdown and weightings on [Blackboard]. 


# Grade
Your grade and the breakdown is shown below

| Component                                        | MARKS    |
| -------------------------------------------------|:--------:|
| Problem Analysis (UML & Pseudo-code discussion)  | 30.00%   |
| Playability & Innovation                         | 63.00%   |
| Technical Implementation                         | 72.00%   |
| ------                                           | -------- |
| **Total**                                        |**63.75%**|


#### Additional Feedback
When being moderated, the second marker wished to share some of their thoughts as well, so there are two lots of feedback for you.

> **1st Marker**  
> UML diagram needed some work but did the job, but the pseudo-code and discussion was missing. A decent recreation of the basic mechanics and great to see some basic physics in the game world. The biggest issue I had was how difficult accurately launching the birds was. It was often much easier to launch with lots of air and the feel of that mechanic is key to the enjoyability of the game. The UI could also do with improvement.
>
> A very tidy code-base which is slightly underdeveloped. Whilst functions were short and easy to follow, there was some unneeded classes at play and a some further abstraction would have helped. For example: the real need for Circle and Rectangle as classes wasn't overly clear. Good work though on catching the memory leaks and for providing easy to reason code. 

> **2nd Marker**  
This student has demonstrated a good understanding of basic OOP concepts and has a general regard for game design patterns, however they would benefit from taking time to study higher level software design concepts and how to decompose their objects into digestible groups. It would have been nice to see clear and succinct means of handling related systems. For instance, if all of their gameplay objects initialisation, update and rendering were handled in dedicated methods it would be very clear to determine the order in which systems are being handled. 
>
>It also means from a very high level, we can handle exceptions and inform the game of any issues on a case by case basis. There is some consideration of this with methods such as setupBirds and setupPigs, but when looking at the game through Angry::Init and like Game.h methods, I don’t care about particular objects, I just want to know did ASGE systems get setup correctly, did the game objects get setup correctly.  **This might look like:**
```cpp
Bool Angry::Init()
{
    initialiseEngine();
    initialiseGameObjects();
    …
}  
```


[Blackboard]: <https://blackboard.uwe.ac.uk>