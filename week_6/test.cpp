#include <memory>
#include <iostream>
#include <string>
 
int main()
{
    {
        // default allocator for ints
        std::allocator<int> alloc;
 
        // demonstrating the few directly usable members
        //static_assert(std::is_same<int, decltype(alloc)::value_type>);
        int* p = alloc.allocate(1);  // space for one int
        alloc.deallocate(p, 1);      // and it is gone
 
        // Even those can be used through traits though, so no need
        using traits_t = std::allocator_traits<decltype(alloc)>; // The matching trait
        p = traits_t::allocate(alloc, 1);
        traits_t::construct(alloc, p, 7);       // construct the int
        std::cout << *p << '\n';
        traits_t::deallocate(alloc, p, 1);      // deallocate space for one int
    }
 
    {
        // default allocator for strings
        std::allocator<int> alloc;
        // matching traits
        using traits_t = std::allocator_traits<decltype(alloc)>;
	int gg = 123;
	int* chr = &gg;	
	std::cout<< chr<<'\n';
	std::cout<< *chr<<'\n';
        // Rebinding the allocator using the trait for strings gets the same type
        //traits_t::rebind_alloc<std::string> alloc_ = alloc;
 
        int* p = traits_t::allocate(alloc, 2); // space for 2 strings
 
        traits_t::construct(alloc, p, std::move(*chr));
        std::cout<< p<<'\n';	
        std::cout << p[0] << ' ' << p[1] << '\n';

        std::cout << *chr<<'\n';
        traits_t::destroy(alloc, p + 1);
        traits_t::destroy(alloc, p);
        traits_t::deallocate(alloc, p, 2);
    }
}
