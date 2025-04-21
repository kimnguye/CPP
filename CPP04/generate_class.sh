#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: ./generate_class.sh ClassName"
    exit 1
fi

CLASS_NAME=$1
HEADER_FILE="${CLASS_NAME}.hpp"
SOURCE_FILE="${CLASS_NAME}.cpp"
INCLUDE_GUARD="$(echo ${CLASS_NAME}_HPP | tr '[:lower:]' '[:upper:]')"

# Créer le fichier .hpp
cat <<EOF > $HEADER_FILE
#ifndef ${INCLUDE_GUARD}
#define ${INCLUDE_GUARD}

#include <iostream>

class ${CLASS_NAME}
{
public:
    ${CLASS_NAME}();                  
    ~${CLASS_NAME}();                           
    ${CLASS_NAME}(const ${CLASS_NAME} &other);  
    ${CLASS_NAME} &operator=(const ${CLASS_NAME} &other);
};

#endif
EOF

# Créer le fichier .cpp
cat <<EOF > $SOURCE_FILE
#include "${CLASS_NAME}.hpp"

${CLASS_NAME}::${CLASS_NAME}()
{
	std::cout << "${CLASS_NAME} default constructor called" << std::endl;
}

${CLASS_NAME}::~${CLASS_NAME}()
{
	std::cout << "${CLASS_NAME} destructor called" << std::endl;
}

${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME} &other)
{
	std::cout << "${CLASS_NAME} copy constructor called" << std::endl;
	*this = other;
}

${CLASS_NAME} &${CLASS_NAME}::operator=(const ${CLASS_NAME} &other)
{
	std::cout << "${CLASS_NAME} copy assignment operator called" << std::endl;
	if (this != &other)
	{
		
	}
	return *this;
}
EOF

echo "✅ Fichiers ${HEADER_FILE} et ${SOURCE_FILE} créés."