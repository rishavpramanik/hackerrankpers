def is_leap(year):
    if year//100==year/100:
        if year//400==year/400:
            return True
        else :
            return False
    if year//4==year/4:
        return True
    return False
