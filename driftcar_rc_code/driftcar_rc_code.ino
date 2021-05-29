

'----- Motors and servos setup
symbol drive = 1        ' set servo pin number for drive 
symbol totalhalt = 118    ' set value to stand still - in my setup
symbol speedahead = 75       ' set value to drive forward- in my setup
symbol speedreverse = 225   ' set value to reverse

symbol steer = 2       ' set servo pin number for steering
symbol ahead = 176       ' set value for front wheels to be in neutral position - in my setup
symbol turnleft = 225      ' set value for left turn - in my setup
symbol turnright = 75      ' set value for right turn- in my setup

'----- SRF05 setup
symbol SRF05_IO = 4                   ' In/out Pin connected to center pin of SRF05
symbol RangeF = w3                   ' define the variable to hold Front SRF05 value

'----- Program variables setup

Symbol danger = 400       'Used in the main program when judging what to do within certain tresholds
Symbol objectinfront = 700          'Used in the main program when judging what to do within certain tresholds
symbol freespace = 800               'Used in the main program when judging what to do within certain tresholds


'----- Initiate program
servo drive, totalhalt                     ' set pin into servo mode, and do notin
servo steer, ahead                         ' set pin into servo mode, and do notin


'----- Main program

Main:
gosub Readrange
if rangeF > danger then
  hans:
  gosub Readrange
  servopos drive, speedahead  
  if rangeF > freespace then
    servopos steer, turnright
    goto hans
  endif
    if rangeF < objectinfront then
    servopos steer, turnleft
    goto main
  endif 
    if rangeF > objectinfront and rangeF < freespace then
    servopos steer, ahead
  endif
else
  servopos drive, speedreverse

  goto main
endif

goto main 


'----- Sub routine to work with the SRF05
ReadRange: ' sub routine to read distance
PULSOUT SRF05_IO, 10         ' issue 10uS trigger pulse
PULSIN SRF05_IO, 1, RangeF ' measure echo time, put it into the variable RangeF
pause 10
return ' end of sub routine
