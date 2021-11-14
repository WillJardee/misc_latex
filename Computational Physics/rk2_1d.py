import numpy as np
def rk2_1d(y0, t0, tf, dt, deriv_func):
    """
    Numerically integrate a first order ODE using the Runga-Kutta 
      second-order method.

    Input
    ----------
    y0:         Initial dependent-variable value
    t0,tf:      Initial,final independent-variable value
    dt:         Step size for the independent variable
    deriv_func: Function to be numerically integrated.

    Output
    ----------
    t:          Array of independent-variable values 
                  t = [t[0], t[1], t[2], ... , t[n_steps]]
    y:          Array of corresponding dependent-variable values
                  y = [y[0], y[1], y[2], ... , y[n_steps]]
    """

    t = np.arange(t0, tf+dt, dt) # starts at t0 and makes steps of size dt
    n_steps = len(t)             # number of steps to get to tf
    y = np.zeros(n_steps)        # create a vector to put answers into
    y[0] = y0                    # initial condition

    for n in range(n_steps-1):
        # Take a half step
        f = deriv_func(y[n],t[n])
        y_star = y[n] + 0.5 * dt * f

        # Now take the full step
        t_star = t[n] + 0.5 * dt
        f_star = deriv_func(y_star, t_star)
        y[n+1] = y[n] + dt*f_star

    return t, y
