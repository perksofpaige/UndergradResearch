def password_check(password, minimum_requirement):
    SpecialSym = ['!', '$', '_', '@', '#', '%', '^', '&', '*', '(', ')']
    count = 0

    # DO ALL CHECKS
    if len(password) < 8:
        pass
    else:
        count += 1

    if not any(char.isdigit() for char in password):
        pass
    else:
        count += 1

    if not any(char.isupper() for char in password):
        pass
    else:
        count += 1

    if not any(char.islower() for char in password):
        pass
    else:
        count += 1

    if not any([char in SpecialSym for char in password]):
        pass
    else:
        count += 1

    # RETURN
    if count >= minimum_requirement:
        return True


def main():
    # INPUT from user
    file_with_passwords = input("Enter filename: ")


    # get list of passwords from file
    passwords = None
    with open(file_with_passwords) as f:
        passwords = [line.rstrip() for line in f]

    acceptable_passwords = []

    # CHANGE NUMBER OF REQUIRED REQUIREMENTS HERE
    minimum_requirement = 2

    for password in passwords:
        if password_check(password, minimum_requirement):
            acceptable_passwords.append(password)

    length = len(acceptable_passwords)

    print('Number of passwords with at least', minimum_requirement, 'requirements met: ', length)

    [print('Acceptable Passwords: ', i) for i in acceptable_passwords]


if __name__ == '__main__':
    main()
