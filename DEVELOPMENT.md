# Development
 - **4/21/20** Linked cinder block library Cinder-WMFVideo
   - First plan how to structure the game
 - **4/21/20** Structured my game into different classes: location, alien, alienwave, engine, etc.
 - **4/22/20** First create the alien and alien waves.
   - FillWave function that adds alien object to the deque wave. 
   - Getting deque out of range error. Go to office hour.
 - **4/23/20** The alien wave should move certain times to one direction, then step down, then certain times to
               opposite direction.
   - Create player.
   - Fill out the keyDown (and create keyUp) function so the player does something when specific key is pressed.
   - Create draw functions to draw alien waves (first as a square).            
 - **4/24/20** Create the projectile that is fired when the player presses space bar.
   - Having problem with firing the projectile. After the projectile is fired, if I let go of space bar or press any 
                button, the projectile disappears/resets. How do I fix this?
   - Go to office hour.
   - Also fixed the error where the player and alien wave leaves its own object behind.
 - **4/28/20** Create pointer projectile. Now I can delete the projectile and prevent memory leaks                             
---
