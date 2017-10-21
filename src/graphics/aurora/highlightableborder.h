//
// Created by aqueiros on 18/10/17.
//

#ifndef XOREOS_HIGHLIGHTABLEBORDER_H
#define XOREOS_HIGHLIGHTABLEBORDER_H

#include "src/graphics/aurora/borderquad.h"
#include "src/graphics/aurora/highlightable.h"

namespace Graphics {
    namespace Aurora {
        class HighlightableBorder : public BorderQuad, public Highlightable {
        public :
            HighlightableBorder(const Common::UString &edge, const Common::UString &corner, float x, float y, float w, float h, const Common::UString &cornerH, const Common::UString &edgeH);
            ~HighlightableBorder();

            void render(RenderPass pass);

            void setHighlightCornerTexture(const TextureHandle& corner);
            void setHighlightEdgeTexture(const TextureHandle& edge);

        private:
            TextureHandle _cornerH;
            TextureHandle _edgeH;

            TextureHandle _edge;
            TextureHandle _corner;
        };
    }
}


#endif //XOREOS_HIGHLIGHTABLEBORDER_H
