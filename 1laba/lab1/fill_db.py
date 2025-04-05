import os
import django
import random
from faker import Faker

os.environ.setdefault("DJANGO_SETTINGS_MODULE", "lab1.settings")

django.setup()

from mainapp.models import historicalEvents  

fake = Faker()

def fill_database(n=1000):
    objects = []
    for _ in range(n):
        obj = historicalEvents(
            start_date=fake.date_between(start_date='-1000y', end_date='today'),
            end_date=fake.date_between(start_date='-990y', end_date='today'),
            title=fake.word().capitalize(),
            category=fake.random_element(['war', 'science', 'politics', 'discovery', 'revolution']),
            is_peaceful=random.choice([True, False, None])
        )
        objects.append(obj)

    historicalEvents.objects.bulk_create(objects)
    print(f'Успешно добавлено {n} записей!')

if __name__ == "__main__":
    fill_database()
