import turtle
import serial

# Initialize serial communication with Arduino
ser = serial.Serial('COM3', 9600, timeout=0.1)  # Replace 'COM3' with your Arduino's port

# Constants for screen boundaries
SCREEN_WIDTH = 600
SCREEN_HEIGHT = 600

try:
    
    # Function to read and process serial commands from Arduino
    def read_serial():
        try:
            line = ser.readline().decode('utf-8').strip()
            if line == "PENUP":
                lift_pen()
            elif line == "PENDOWN":
                lower_pen()
            elif line == "COLORRED":
                change_color("red")
            elif line == "COLORGREEN":
                change_color("green")
            elif line == "COLORBLUE":
                change_color("blue")
            elif line == "COLORYELLOW":
                change_color("yellow")
            elif line == "STAMP":
                make_stamp()
            elif line == "DOT":
                make_dot()
            else:
                values = line.split(',')
                if len(values) == 2:
                    try:
                        forwardBackward = int(values[0])
                        turn = int(values[1])
                        move_turtle(forwardBackward, turn)
                    except ValueError:
                        pass  # Ignore invalid integer values
        except UnicodeDecodeError:
            pass  
    
        turtle.ontimer(read_serial, 20)  # Read serial every 20ms for faster updates
    
    # Function to move the turtle based on joystick values
    def move_turtle(forwardBackward, turn):
        if abs(forwardBackward) > 5:  # Adjust sensitivity threshold as needed
            turtle.forward(forwardBackward / 10)  # Adjust speed with division
        if abs(turn) > 5:  # Adjust sensitivity threshold as needed
            turtle.right(turn / 5)  # Adjust turning speed with division
        
        # Check boundaries
        x, y = turtle.position()
        if x > SCREEN_WIDTH / 2:
            turtle.setx(SCREEN_WIDTH / 2)
        elif x < -SCREEN_WIDTH / 2:
            turtle.setx(-SCREEN_WIDTH / 2)
            
        if y > SCREEN_HEIGHT / 2:
            turtle.sety(SCREEN_HEIGHT / 2)
        elif y < -SCREEN_HEIGHT / 2:
            turtle.sety(-SCREEN_HEIGHT / 2)
    
    # Function to lift turtle's pen
    def lift_pen():
        turtle.penup()
    
    # Function to lower turtle's pen
    def lower_pen():
        turtle.pendown()
    
    # Function to change the color of the turtle's pen
    def change_color(color):
        turtle.pencolor(color)
    
    # Function to make a turtle stamp
    def make_stamp():
        turtle.stamp()
    
    # Function to make a dot
    def make_dot():
        turtle.dot()
    
    # Turtle setup
    turtle.speed(3)  # Increased speed for faster movement
    turtle.shape("turtle")
    turtle.bgcolor("purple1")
    
    # Set initial position at center
    turtle.penup()
    turtle.goto(0, 0)
    turtle.pendown()
    
    # Start reading serial data
    read_serial()
    
    # Start turtle main loop
    turtle.mainloop()

finally:
    
    # Close serial connection when done
    ser.close()