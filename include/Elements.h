#include <GL/glew.h>
// Class which holds the OpenGL most important elements and its base construction

class Elements{

    public:
        unsigned int VBO;
        unsigned int VAO;
        unsigned int EBO;

        Elements(float* vertices, unsigned int* indices, int size_of_vertices, int size_of_indices);
        ~Elements();

        void BindBuffer(GLenum target, unsigned int buffer);
        void BufferData(GLenum target, GLsizeiptr size, const void * data, GLenum usage);
        void BindVertexArray(unsigned int buffer);
};
