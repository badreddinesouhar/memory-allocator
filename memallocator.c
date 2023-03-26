/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:12:30 by bsouhar           #+#    #+#             */
/*   Updated: 2023/03/26 20:14:58 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
 * Allocate memory using sbrk.
 * 
 * This function takes a size_t argument representing the number of bytes to allocate
 * and returns a void pointer to the first byte of the allocated memory block. It calls
 * sbrk to increase the program's data segment size by the specified number of bytes and
 * returns a pointer to the start of the new memory block. If sbrk returns an error (-1),
 * it returns a null pointer.
 * 
 * Note that this implementation does not keep track of the size of the allocated memory
 * block or whether the block is in use or not. Therefore, it may be difficult or impossible
 * to properly deallocate the memory block using free unless this information is stored
 * elsewhere.
 */
 
/*void *malloc(size_t size)
 {
     void *block;
 
     block = sbrk(size);
     if (block == (void *) -1)
         return NULL;
     return block;
 }
*/

/*
 * This header structure is used to keep track of the size of the memory block that has been allocated,
 * which is necessary for reallocating and deallocating the memory later on. Additionally, it tracks
 * whether the block is currently in use or not, since we cannot free a memory block that is not at the
 * end of the heap. If a block is not in use, it will be marked as free.
 *
 * The structure also maintains a reference to the next memory block in case there is another block of
 * memory located between our current memory block and the end of the heap. This allows us to keep track
 * of the address of the next memory block and properly manage our memory allocation.
 */ 

struct header_t {
    size_t size;
    unsigned is_free;
    struct header_t *next;
};
