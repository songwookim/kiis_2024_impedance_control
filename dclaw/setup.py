from setuptools import find_packages, setup

package_name = 'dclaw'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='hanlab',
    maintainer_email='hanlab@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'dclaw_sim = dclaw.dclaw_sim:main',# added
            'dclaw_real = dclaw.dclaw_real:main',# added
            'sensor_real = dclaw.sensor_real:main',# added
        ],
    },
)
