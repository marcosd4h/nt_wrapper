#pragma once
#include "../detail/offset_iterator.hpp"
#include "../result.hpp"

namespace ntw::sys {

    struct loaded_module {
        std::uint16_t offset_to_next;
        void*         section;
        void*         mapped_base;
        void*         image_base;
        ulong_t       image_size;
        ulong_t       flags;
        std::uint16_t load_order_idx;
        std::uint16_t init_order_idx;
        std::uint16_t load_count;
        std::uint16_t file_name_offset;
        char          path[256];
        ulong_t       image_checksum;
        ulong_t       timestamp;
        void*         default_base;

        /// \brief Returns a null terminated file name string.
        NTW_INLINE const char* name() const noexcept;

        /// \brief Returns string_view which contains the file name
        NTW_INLINE std::string_view name_view() const noexcept;

        /// \brief Returns a string_view of the full file path
        NTW_INLINE std::string_view path_view() const noexcept;

        using range_type = detail::offset_iterator_range<loaded_module, true>;
    };

    template<class Range>
    ntw::result<typename loaded_module::range_type> loaded_modules(Range&& buffer);

} // namespace ntw::sys

#include "impl/modules.inl"