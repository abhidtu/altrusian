//
// Created by linux on 6/2/16.
//

#include "LinkedList.h"

namespace LibAlDs {
    namespace Lists {

    /**
    * Tn = O(1)
    */
        void LinkedList::deleteFromBeginning() {

            if (isEmpty()) return;

            if (containsSingleNode()) {
                return detachFromSingleNodeList();
            }

            detachFromBeginning();

        }

     /**
     * Tn = O(N)
     */
        void LinkedList::deleteFromEnd() {

            if (isEmpty()) return;

            if (containsSingleNode()) {
                return detachFromSingleNodeList();
            }

            detachFromEnd();

        }


        int LinkedList::size() {
            return NumNodes;
        }

    }
}