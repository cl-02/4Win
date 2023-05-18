#ifndef HEADER_HPP
#define HEADER_HPP

namespace Dummy
{
    class TestClass
    {
    public:
        // Default constructor
        TestClass() = default;

        // Constructor setting member
        TestClass(int i)
            : m_i(i)
        {
        }

        // Print short test message via std::cout
        void print();

        int getMember()
        {
            return m_i;
        }

        void setMember(int i)
        {
            m_i = i;
        }

    private:
        int m_i{0};
    };

} // namespace Dummy

#endif // HEADER_HPP