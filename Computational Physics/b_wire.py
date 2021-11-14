import numpy as np
def b_wire(x, y):
    """
    Finds the magnetic field at point (x,y) from a wire of current 'I' located at the origin.
    Inputs
    ----------
    x: x value (m)
    y: y value (m)
    
    Output
    ----------
    b_field: Array of the Magnetic field at (x,y), b_field[0] is the x component b_field[1] is the y. 
    """
    I = -10 #Current (A) negative is into the page, possitive is out of the page
    mu = 4*np.pi*10**-7 #permeability of free space (H/m or T⋅m/A)
    s = np.sqrt(x**2 + y**2)
    theta = np.arctan2(y, x) #Remember arctan2 has inputs (y,x) for some reason.
    phi_hat = np.array([-np.sin(theta), np.cos(theta)])
    b_field = mu*I / (2*np.pi * s) * phi_hat
    return b_field
