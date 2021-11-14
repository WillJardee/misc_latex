def newton(func_name, deriv_name, x_guess):
    """
    Find the roots of the input function func_name using newtons method

    Input
    ----------
    func_name:   Name of the function that we want to solve for. This should
                 either be a built in function or a .py file name.

    deriv_name:  Name of the derivative of function_name

    x_guess:     Newton's Method needs and Initial guess at the solutions.
                 Doesn't have to be a good guess.  The better the guess, the
                 faster you'll get to the correct answer

    Output
    ----------
    x_zero: Returns the value that gives f(x_zero) = 0
    """

    # Start by setting x_zero equal to my initial guess
    x_zero = x_guess

    for i in range(20):
        f = func_name(x_zero)
        fp = deriv_name(x_zero)
        delta_x = -f/fp
        x_zero += delta_x   # This is the same as x_zero = x_zero + delta_x

        # If x_zero is within the tolerance then we can return the answer and quit
        if abs(delta_x) < 0.5e-5 * abs(x_zero):
            return x_zero

    # If we didn't find an accurate answer after 20 tries, we say it's good enough
    # and return what ever answer we have. Remember it’s possible to get stuck in
    # an infinite loop with Newton’s method so having an emergency exit built into
    # the code is a good idea.
    print("Closest answer after 20 tries is", x_zero)
    return x_zero
