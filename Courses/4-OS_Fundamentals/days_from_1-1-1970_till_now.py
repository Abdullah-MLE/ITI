
from datetime import date

def is_leap(year):
    return year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)

def days_in_year(year):
    return 366 if is_leap(year) else 365

def days_in_month(month, year):
    months = [31, 28, 31, 30, 31, 30,
              31, 31, 30, 31, 30, 31]
    if month == 2 and is_leap(year):
        return 29
    return months[month - 1]

def main():
    value = input("Enter date (DD-MM-YYYY) or 'today': ")

    if value == "today":
        today = date.today()
        day, month, year = today.day, today.month, today.year
    else:
        day, month, year = map(int, value.split("-"))

    total = 0

    for y in range(1970, year):
        total += days_in_year(y)

    for m in range(1, month):
        total += days_in_month(m, year)

    total += day - 1

    print(total)

if __name__ == "__main__":
    main()
